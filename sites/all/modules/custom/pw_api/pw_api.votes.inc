<?php

/*
 * @file
 * pw_api.votes.inc
 */


/**
 *
 * @return array $votes
 *   All votes to petitions as array.
 */

function pw_api_petitions($parliament) {

  $votes = array();

    // translate uuid into parliament name
  if(preg_match('/[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}/i', $parliament, $uuid)){
    $parliament_term = entity_uuid_load('taxonomy_term', $uuid);
  }
  else{
    $parliament_term = taxonomy_get_term_by_name($parliament, 'parliaments');
  }
  $parliament_term = array_pop($parliament_term);

   // query for all nodes of type petition
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'pw_petition')
  ->fieldCondition('field_parliament', 'tid', $parliament_term->tid)
  ->propertyCondition('status', NODE_PUBLISHED)
  ->propertyOrderBy('created', 'DESC');
  $result_nodes = $query->execute();

  if(isset($result_nodes['node'])){

    foreach(array_keys($result_nodes['node']) as $target_node_id){

      $node = node_load($target_node_id);
      $votes['petition_'.$target_node_id] = array();
      $votes['petition_'.$target_node_id]['title'] = $node->title;
      $votes['petition_'.$target_node_id]['uuid'] = $node->uuid;
      $date_field = field_get_items('node', $node, 'field_petition_end_date');
      $date_petition = substr($date_field[0]['value'], 0, 10);
      $votes['petition_'.$target_node_id]['date'] = $date_petition;
      $status = field_get_items('node', $node, 'field_petition_status');
      $votes['petition_'.$target_node_id]['status'] = $status[0]['value'];
      $votes['petition_'.$target_node_id]['url'] = url('node/'.$node->nid, array('absolute' => TRUE));
      if($status[0]['value'] == 'passed_parliament'){
        $votes['petition_'.$target_node_id]['votes'] = pw_api_add_votes($parliament_term, $target_node_id, $poll_date);
      }
      else{
        $votes['petition_'.$target_node_id]['votes'] = '';
      }
    }
  }

  return array('petitions' => $votes);
}

/**
 *
 * @return array $votes
 *   All votes to polls as array.
 */

function pw_api_polls($parliament) {

  $votes = array();

    // translate uuid into parliament name
  if(preg_match('/[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}/i', $parliament, $uuid)){
    $parliament_term = entity_uuid_load('taxonomy_term', $uuid);
  }
  else{
    $parliament_term = taxonomy_get_term_by_name($parliament, 'parliaments');
  }
  $parliament_term = array_pop($parliament_term);

   // query for all nodes of type poll
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'poll')
  ->fieldCondition('field_parliament', 'tid', $parliament_term->tid)
  ->propertyCondition('status', NODE_PUBLISHED)
  ->propertyOrderBy('created', 'DESC');
  $result_nodes = $query->execute();

  if(isset($result_nodes['node'])){

    foreach(array_keys($result_nodes['node']) as $target_node_id){

      $node = node_load($target_node_id);
      $votes['poll_'.$target_node_id] = array();
      $votes['poll_'.$target_node_id]['title'] = $node->title;
      $votes['poll_'.$target_node_id]['uuid'] = $node->uuid;
      $date_field = field_get_items('node', $node, 'field_poll_date');
      $poll_date = substr($date_field[0]['value'], 0, 10);
      $votes['poll_'.$target_node_id]['date'] = $poll_date;
      $status = field_get_items('node', $node, 'field_voted');
      if($status[0]['value'] == '1'){
        $votes['poll_'.$target_node_id]['status'] = 'abgestimmt';
        $votes['poll_'.$target_node_id]['votes'] = pw_api_add_votes($parliament_term, $target_node_id, $poll_date);
      }
      else{
        $votes['poll_'.$target_node_id]['status'] = $poll_date > date('Y-m-d')?'anstehend':'unbekannt';
        $votes['poll_'.$target_node_id]['votes'] = '';
      }
      $votes['poll_'.$target_node_id]['url'] = url('node/'.$node->nid, array('absolute' => TRUE));
      //@TODO: Categories, Tags
    }
  }

  return array('polls' => $votes);
}

function pw_api_add_votes($parliament_term, $target_node_id, $vote_date){

  // return array
  $votes = array();

  // query for all votes on target node
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'vote')
  ->fieldCondition('field_parliament', 'tid', $parliament_term->tid)
  ->fieldCondition('field_vote_node', 'target_id', $target_node_id)
  ->propertyCondition('status', NODE_PUBLISHED)
  ->propertyOrderBy('created', 'DESC');
  $result_votes = $query->execute();

  if(isset($result_votes['node'])){

    $query = db_select('node', 'n');
    $query->condition('n.nid', array_keys($result_votes['node']));

    // join taxonomy terms to retrieve voting behaviour
    $query->join('field_data_field_vote', 'vote', "n.nid = vote.entity_id AND vote.bundle = 'vote'");
    $query->join('taxonomy_term_data', 'vote_term', "vote.field_vote_tid = vote_term.tid");
    $query->join('field_data_field_votes_label', 'vote_label', "vote_term.tid = vote_label.entity_id AND vote_label.entity_type = 'taxonomy_term'");
    $query->addField('vote_label', 'field_votes_label_value', 'vote_label');

    // join target user to retrieve user data
    $query->join('field_data_field_vote_user', 'vote_user', "n.nid = vote_user.entity_id AND vote_user.bundle = 'vote'");
    $query->join('user_archive_cache', 'uac', "vote_user.field_vote_user_target_id = uac.uid");
    $query->addField('uac', 'vid');
    $query->addField('uac', 'fraction_name', 'fraction');
    _pw_uac_add_conditions($query, array(
      'parliament' => $parliament_term->name,
      'roles' => 'deputy',
      'date' => $vote_date,
      )
    );

    //$query->groupBy('uac.uid');

    // join users to retrieve uuid
    $query->join('users', 'u', "vote_user.field_vote_user_target_id = u.uid");
    $query->addField('u', 'uuid');

    // join to retrieve first name
    $query->join('field_revision_field_user_fname', 'u_fname', "uac.vid = u_fname.revision_id");
    $query->addField('u_fname', 'field_user_fname_value', 'first_name');

    // join to retrieve last name
    $query->join('field_revision_field_user_lname', 'u_lname', "uac.vid = u_lname.revision_id");
    $query->addField('u_lname', 'field_user_lname_value', 'last_name');

    // join to retrieve title name
    $query->leftJoin('field_revision_field_user_title', 'u_degree', "uac.vid = u_degree.revision_id");
    $query->addField('u_degree', 'field_user_title_value', 'degree');

    // join to retrieve party
    $query->join('field_revision_field_user_party', 'u_party', "uac.vid = u_party.revision_id");
    $query->join('taxonomy_term_data', 'party_term', "u_party.field_user_party_tid = party_term.tid");
    $query->addField('party_term', 'name', 'party');

    // join to retrieve constituency
    $query->leftJoin('field_revision_field_user_constituency', 'u_constituency', "uac.vid = u_constituency.revision_id");
    $query->leftJoin('taxonomy_term_data', 'constituency_term', "u_constituency.field_user_constituency_tid = constituency_term.tid");
    $query->addField('constituency_term', 'name', 'constituency');

    // sort
    $query->orderBy('u_lname.field_user_lname_value');
    $query->orderBy('u_fname.field_user_fname_value');

    // get results
    $result = $query->execute();

    // fetch and write results
    while($record = $result->fetchObject()){
      $vote = array();
      $vote['name'] = trim($record->degree.' '.$record->first_name.' '.$record->last_name);
      $vote['uuid'] = $record->uuid;
      $vote['party'] = $record->party;
      $vote['fraction'] = $record->fraction;
      $vote['constituency'] = $record->constituency;
      $vote['vote'] = $record->vote_label;
      $votes['deputy_'.$record->vid] = $vote;
    }
  }

  return $votes;
}
