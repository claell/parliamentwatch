<?php
/**
 * @file
 * pw_vote.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_vote_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'pw_vote_positions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Vote Positions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'PW Vote Positions';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'Weitere Positionen anzeigen';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'clearfix';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'pw-list-seperated';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Beziehung: Inhalt: Autor */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sortierkriterien: Inhalt: Aktualisierungszeitpunkt */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vote' => 'vote',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Benutzer: Rollen */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    181527986 => '181527986',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  /* Filterkriterium: Inhalt: Node Reference (field_vote_node) */
  $handler->display->display_options['filters']['field_vote_node_target_id']['id'] = 'field_vote_node_target_id';
  $handler->display->display_options['filters']['field_vote_node_target_id']['table'] = 'field_data_field_vote_node';
  $handler->display->display_options['filters']['field_vote_node_target_id']['field'] = 'field_vote_node_target_id';
  $handler->display->display_options['filters']['field_vote_node_target_id']['operator'] = 'regular_expression';
  $handler->display->display_options['filters']['field_vote_node_target_id']['value']['value'] = '.*51264.*';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['pw_vote_positions'] = array(
    t('Master'),
    t('PW Vote Positions'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('weiter'),
    t('letzte Seite »'),
    t('Weitere Positionen anzeigen'),
    t('Autor'),
    t('Block'),
  );
  $export['pw_vote_positions'] = $view;

  $view = new view();
  $view->name = 'pw_vote_profile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Vote Profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Abstimmungsverhalten';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'Alle anzeigen';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['pager']['options']['load_all'] = 1;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_vote' => 'field_vote',
    'view_node' => 'view_node',
    'field_petition_end_date' => 'field_petition_end_date',
    'title' => 'title',
    'field_votes_label' => 'field_votes_label',
    'nothing' => 'nothing',
    'body' => 'body',
    'field_vote_node' => 'field_vote_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_petition_end_date';
  $handler->display->display_options['style_options']['info'] = array(
    'field_vote' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_petition_end_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_votes_label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_vote_node' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_vote_user_target_id']['id'] = 'field_vote_user_target_id';
  $handler->display->display_options['relationships']['field_vote_user_target_id']['table'] = 'field_data_field_vote_user';
  $handler->display->display_options['relationships']['field_vote_user_target_id']['field'] = 'field_vote_user_target_id';
  $handler->display->display_options['relationships']['field_vote_user_target_id']['required'] = TRUE;
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_vote_node_target_id']['id'] = 'field_vote_node_target_id';
  $handler->display->display_options['relationships']['field_vote_node_target_id']['table'] = 'field_data_field_vote_node';
  $handler->display->display_options['relationships']['field_vote_node_target_id']['field'] = 'field_vote_node_target_id';
  $handler->display->display_options['relationships']['field_vote_node_target_id']['required'] = TRUE;
  /* Beziehung: Inhalt: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'Votes Term';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'votes' => 'votes',
    'area_codex' => 0,
    'blogcategories' => 0,
    'blogtags' => 0,
    'committee' => 0,
    'committee_types' => 0,
    'constituency' => 0,
    'dialogue_tags' => 0,
    'dialogue_topics' => 0,
    'electoral_region' => 0,
    'fraction' => 0,
    'pw_kc_votes' => 0,
    'election_list' => 0,
    'list_position' => 0,
    'parliaments' => 0,
    'party' => 0,
    'political_roles' => 0,
    'pw_profile_roles_for_view_mode_switch' => 0,
    'sidejob_jobs' => 0,
    'sidejob_organizations' => 0,
    'sidejob_sectors' => 0,
    'tags' => 0,
  );
  /* Feld: Excluded | Vote */
  $handler->display->display_options['fields']['field_vote']['id'] = 'field_vote';
  $handler->display->display_options['fields']['field_vote']['table'] = 'field_data_field_vote';
  $handler->display->display_options['fields']['field_vote']['field'] = 'field_vote';
  $handler->display->display_options['fields']['field_vote']['ui_name'] = 'Excluded | Vote';
  $handler->display->display_options['fields']['field_vote']['label'] = '';
  $handler->display->display_options['fields']['field_vote']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_vote']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_vote']['element_label_class'] = '[field_vote] block vote';
  $handler->display->display_options['fields']['field_vote']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_vote']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_vote']['type'] = 'taxonomy_term_reference_plain';
  /* Feld: Excluded | Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['fields']['view_node']['ui_name'] = 'Excluded | Link';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alt'] = 'zur Petition';
  $handler->display->display_options['fields']['view_node']['alter']['link_class'] = 'icon-poll';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'zum Petitions-Check';
  $handler->display->display_options['fields']['view_node']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['view_node']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['view_node']['node_in_colorbox_rel'] = '';
  /* Feld: Inhalt: End Date */
  $handler->display->display_options['fields']['field_petition_end_date']['id'] = 'field_petition_end_date';
  $handler->display->display_options['fields']['field_petition_end_date']['table'] = 'field_data_field_petition_end_date';
  $handler->display->display_options['fields']['field_petition_end_date']['field'] = 'field_petition_end_date';
  $handler->display->display_options['fields']['field_petition_end_date']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['fields']['field_petition_end_date']['label'] = 'Datum';
  $handler->display->display_options['fields']['field_petition_end_date']['settings'] = array(
    'format_type' => 'date_only_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Petition';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alt'] = 'zur Petition';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Feld: Taxonomie-Begriff: Label */
  $handler->display->display_options['fields']['field_votes_label']['id'] = 'field_votes_label';
  $handler->display->display_options['fields']['field_votes_label']['table'] = 'field_data_field_votes_label';
  $handler->display->display_options['fields']['field_votes_label']['field'] = 'field_votes_label';
  $handler->display->display_options['fields']['field_votes_label']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_votes_label']['label'] = 'Stimmverhalten';
  $handler->display->display_options['fields']['field_votes_label']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_votes_label']['alter']['text'] = '<div class="[field_vote] vote block">[field_votes_label]</div>';
  $handler->display->display_options['fields']['field_votes_label']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_votes_label']['element_class'] = 'pw-voting';
  /* Feld: Global: Details */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Details';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="#" class="toggle-details" title="Begründung und Gesamtergebnis anzeigen"><i class="icon-info"></i> Details<i class="icon-arrow-right"></i></a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Argumentation';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'pw-expander';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Feld: Excluded | Node Reference, Entity ID */
  $handler->display->display_options['fields']['field_vote_node']['id'] = 'field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['table'] = 'field_data_field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['field'] = 'field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['ui_name'] = 'Excluded | Node Reference, Entity ID';
  $handler->display->display_options['fields']['field_vote_node']['label'] = '';
  $handler->display->display_options['fields']['field_vote_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_vote_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_vote_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_vote_node']['settings'] = array(
    'link' => 0,
  );
  /* Sortierkriterien: Inhalt: Datum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Kontextfilter: Inhalt: Politician Reference (field_vote_user) */
  $handler->display->display_options['arguments']['field_vote_user_target_id']['id'] = 'field_vote_user_target_id';
  $handler->display->display_options['arguments']['field_vote_user_target_id']['table'] = 'field_data_field_vote_user';
  $handler->display->display_options['arguments']['field_vote_user_target_id']['field'] = 'field_vote_user_target_id';
  $handler->display->display_options['arguments']['field_vote_user_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_vote_user_target_id']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_vote_user_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_vote_user_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_vote_user_target_id']['default_argument_options']['code'] = '$user = _pw_get_current_user();
return $user->uid;';
  $handler->display->display_options['arguments']['field_vote_user_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_vote_user_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_vote_user_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_vote_user_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_vote_user_target_id']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['field_vote_user_target_id']['validate_options']['type'] = 'either';
  $handler->display->display_options['arguments']['field_vote_user_target_id']['validate_options']['restrict_roles'] = TRUE;
  $handler->display->display_options['arguments']['field_vote_user_target_id']['validate_options']['roles'] = array(
    181527986 => '181527986',
  );
  /* Kontextfilter: Feld: Parliament (field_parliament) */
  $handler->display->display_options['arguments']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['arguments']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_parliament_tid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_parliament_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_argument_options']['code'] = '$term = _pw_get_current_parliament_term();
return $term->tid;';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parliament_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_parliament_tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vote' => 'vote',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Inhalt: End Date (field_petition_end_date) */
  $handler->display->display_options['filters']['field_petition_end_date_value']['id'] = 'field_petition_end_date_value';
  $handler->display->display_options['filters']['field_petition_end_date_value']['table'] = 'field_data_field_petition_end_date';
  $handler->display->display_options['filters']['field_petition_end_date_value']['field'] = 'field_petition_end_date_value';
  $handler->display->display_options['filters']['field_petition_end_date_value']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['filters']['field_petition_end_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_petition_end_date_value']['granularity'] = 'hour';
  $handler->display->display_options['filters']['field_petition_end_date_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_petition_end_date_value']['year_range'] = '-10:+0';
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'pw_petition' => 'pw_petition',
  );

  /* Display: Petitions */
  $handler = $view->new_display('block', 'Petitions', 'petitions');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Abstimmungsverhalten im Petitions-Check';

  /* Display: Polls */
  $handler = $view->new_display('block', 'Polls', 'polls');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_vote' => 'field_vote',
    'view_node' => 'view_node',
    'body' => 'body',
    'field_poll_date' => 'field_poll_date',
    'title' => 'title',
    'field_votes_label' => 'field_votes_label',
    'nothing' => 'nothing',
    'field_vote_node' => 'field_vote_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_poll_date';
  $handler->display->display_options['style_options']['info'] = array(
    'field_vote' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_poll_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_votes_label' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_vote_node' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Excluded | Vote */
  $handler->display->display_options['fields']['field_vote']['id'] = 'field_vote';
  $handler->display->display_options['fields']['field_vote']['table'] = 'field_data_field_vote';
  $handler->display->display_options['fields']['field_vote']['field'] = 'field_vote';
  $handler->display->display_options['fields']['field_vote']['ui_name'] = 'Excluded | Vote';
  $handler->display->display_options['fields']['field_vote']['label'] = '';
  $handler->display->display_options['fields']['field_vote']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_vote']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_vote']['element_label_class'] = '[field_vote] block vote';
  $handler->display->display_options['fields']['field_vote']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_vote']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_vote']['type'] = 'taxonomy_term_reference_plain';
  /* Feld: Excluded | Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['fields']['view_node']['ui_name'] = 'Excluded | Link';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alt'] = 'zur Abstimmung';
  $handler->display->display_options['fields']['view_node']['alter']['link_class'] = 'icon-poll';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'zum Petitions-Check';
  $handler->display->display_options['fields']['view_node']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['view_node']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['view_node']['node_in_colorbox_rel'] = '';
  /* Feld: Excluded | Body Summary */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['fields']['body']['ui_name'] = 'Excluded | Body Summary';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Feld: Inhalt: Poll Date */
  $handler->display->display_options['fields']['field_poll_date']['id'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['table'] = 'field_data_field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['field'] = 'field_poll_date';
  $handler->display->display_options['fields']['field_poll_date']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['fields']['field_poll_date']['label'] = 'Datum';
  $handler->display->display_options['fields']['field_poll_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_poll_date']['settings'] = array(
    'format_type' => 'date_only_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Abstimmung';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alt'] = 'zur Abstimmung';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_rel'] = '';
  /* Feld: Taxonomie-Begriff: Label */
  $handler->display->display_options['fields']['field_votes_label']['id'] = 'field_votes_label';
  $handler->display->display_options['fields']['field_votes_label']['table'] = 'field_data_field_votes_label';
  $handler->display->display_options['fields']['field_votes_label']['field'] = 'field_votes_label';
  $handler->display->display_options['fields']['field_votes_label']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_votes_label']['label'] = 'Stimmverhalten';
  $handler->display->display_options['fields']['field_votes_label']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_votes_label']['alter']['text'] = '<div class="[field_vote] vote block">[field_votes_label]</div>';
  $handler->display->display_options['fields']['field_votes_label']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_votes_label']['element_class'] = 'pw-voting';
  /* Feld: Global: Details */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Global: Details';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="#" class="toggle-details" title="Zusammenfassung und Gesamtergebnis anzeigen"><i class="icon-info"></i> Details<i class="icon-arrow-right"></i></a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Feld: Excluded | Node Reference, Entity ID */
  $handler->display->display_options['fields']['field_vote_node']['id'] = 'field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['table'] = 'field_data_field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['field'] = 'field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['ui_name'] = 'Excluded | Node Reference, Entity ID';
  $handler->display->display_options['fields']['field_vote_node']['label'] = '';
  $handler->display->display_options['fields']['field_vote_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_vote_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_vote_node']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_vote_node']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vote' => 'vote',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'field_vote_node_target_id';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'poll' => 'poll',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  $translatables['pw_vote_profile'] = array(
    t('Master'),
    t('Abstimmungsverhalten'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('weiter'),
    t('letzte Seite »'),
    t('Alle anzeigen'),
    t('Benutzer entity referenced from field_vote_user'),
    t('Inhalt entity referenced from field_vote_node'),
    t('Votes Term'),
    t('zur Petition'),
    t('zum Petitions-Check'),
    t('Datum'),
    t('Petition'),
    t('Stimmverhalten'),
    t('<div class="[field_vote] vote block">[field_votes_label]</div>'),
    t('<a href="#" class="toggle-details" title="Begründung und Gesamtergebnis anzeigen"><i class="icon-info"></i> Details<i class="icon-arrow-right"></i></a>'),
    t('Argumentation'),
    t('Alle'),
    t('Petitions'),
    t('Abstimmungsverhalten im Petitions-Check'),
    t('Polls'),
    t('zur Abstimmung'),
    t('Abstimmung'),
    t('<a href="#" class="toggle-details" title="Zusammenfassung und Gesamtergebnis anzeigen"><i class="icon-info"></i> Details<i class="icon-arrow-right"></i></a>'),
  );
  $export['pw_vote_profile'] = $view;

  $view = new view();
  $view->name = 'pw_vote_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'PW Vote Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Petitionscheck-Suche';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Erweiterte Optionen',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sortieroptionen',
        'combine' => 0,
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
      ),
    ),
    'keyword' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'ss_vote_user_party' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'ss_vote_user_vote_text' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'managed_content';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'zurück';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'Weitere Positionen laden';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'clearfix';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'pw-list-seperated';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<div class="messages warning">Zu Ihrer Auswahl wurden keine Ergebnisse gefunden.</div>';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_vote_user_full_name']['id'] = 'ss_vote_user_full_name';
  $handler->display->display_options['fields']['ss_vote_user_full_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_vote_user_full_name']['field'] = 'ss_vote_user_full_name';
  $handler->display->display_options['fields']['ss_vote_user_full_name']['label'] = 'Name';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_vote_user_party']['id'] = 'ss_vote_user_party';
  $handler->display->display_options['fields']['ss_vote_user_party']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_vote_user_party']['field'] = 'ss_vote_user_party';
  $handler->display->display_options['fields']['ss_vote_user_party']['label'] = 'Partei';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_vote_node_title']['id'] = 'ss_vote_node_title';
  $handler->display->display_options['fields']['ss_vote_node_title']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_vote_node_title']['field'] = 'ss_vote_node_title';
  $handler->display->display_options['fields']['ss_vote_node_title']['label'] = 'Petition';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['im_field_vote']['id'] = 'im_field_vote';
  $handler->display->display_options['fields']['im_field_vote']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['im_field_vote']['field'] = 'im_field_vote';
  $handler->display->display_options['fields']['im_field_vote']['label'] = '';
  $handler->display->display_options['fields']['im_field_vote']['exclude'] = TRUE;
  $handler->display->display_options['fields']['im_field_vote']['element_label_colon'] = FALSE;
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_vote_reason_summary']['id'] = 'ss_vote_reason_summary';
  $handler->display->display_options['fields']['ss_vote_reason_summary']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_vote_reason_summary']['field'] = 'ss_vote_reason_summary';
  $handler->display->display_options['fields']['ss_vote_reason_summary']['label'] = 'Begründung (kurz)';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_vote_reason_full']['id'] = 'ss_vote_reason_full';
  $handler->display->display_options['fields']['ss_vote_reason_full']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_vote_reason_full']['field'] = 'ss_vote_reason_full';
  $handler->display->display_options['fields']['ss_vote_reason_full']['label'] = 'Begründung';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_vote_user_image_uri']['id'] = 'ss_vote_user_image_uri';
  $handler->display->display_options['fields']['ss_vote_user_image_uri']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_vote_user_image_uri']['field'] = 'ss_vote_user_image_uri';
  $handler->display->display_options['fields']['ss_vote_user_image_uri']['label'] = 'User Image URI';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_vote_user_drupal_name']['id'] = 'ss_vote_user_drupal_name';
  $handler->display->display_options['fields']['ss_vote_user_drupal_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_vote_user_drupal_name']['field'] = 'ss_vote_user_drupal_name';
  $handler->display->display_options['fields']['ss_vote_user_drupal_name']['label'] = 'Drupal-Name';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_vote_user_vote_text']['id'] = 'ss_vote_user_vote_text';
  $handler->display->display_options['fields']['ss_vote_user_vote_text']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_vote_user_vote_text']['field'] = 'ss_vote_user_vote_text';
  $handler->display->display_options['fields']['ss_vote_user_vote_text']['label'] = 'Stimme';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['sm_field_vote_node']['id'] = 'sm_field_vote_node';
  $handler->display->display_options['fields']['sm_field_vote_node']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_vote_node']['field'] = 'sm_field_vote_node';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_field_user_lname']['id'] = 'ss_field_user_lname';
  $handler->display->display_options['fields']['ss_field_user_lname']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_field_user_lname']['field'] = 'ss_field_user_lname';
  $handler->display->display_options['fields']['ss_field_user_lname']['label'] = 'Nachname';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_vote_user_vote_sortable']['id'] = 'ss_vote_user_vote_sortable';
  $handler->display->display_options['fields']['ss_vote_user_vote_sortable']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_vote_user_vote_sortable']['field'] = 'ss_vote_user_vote_sortable';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ds_created']['id'] = 'ds_created';
  $handler->display->display_options['fields']['ds_created']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ds_created']['field'] = 'ds_created';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_vote_user_answers']['id'] = 'ss_vote_user_answers';
  $handler->display->display_options['fields']['ss_vote_user_answers']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_vote_user_answers']['field'] = 'ss_vote_user_answers';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_vote_user_gender']['id'] = 'ss_vote_user_gender';
  $handler->display->display_options['fields']['ss_vote_user_gender']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_vote_user_gender']['field'] = 'ss_vote_user_gender';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_vote_user_questions']['id'] = 'ss_vote_user_questions';
  $handler->display->display_options['fields']['ss_vote_user_questions']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_vote_user_questions']['field'] = 'ss_vote_user_questions';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['is_uid']['id'] = 'is_uid';
  $handler->display->display_options['fields']['is_uid']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['is_uid']['field'] = 'is_uid';
  /* Feld: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['fields']['ss_vote_user_id']['id'] = 'ss_vote_user_id';
  $handler->display->display_options['fields']['ss_vote_user_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ss_vote_user_id']['field'] = 'ss_vote_user_id';
  $handler->display->display_options['fields']['ss_vote_user_id']['exclude'] = TRUE;
  /* Sortierkriterien: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['sorts']['ds_changed']['id'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['ds_changed']['field'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['order'] = 'DESC';
  /* Sortierkriterien: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['sorts']['ss_vote_user_vote_sortable']['id'] = 'ss_vote_user_vote_sortable';
  $handler->display->display_options['sorts']['ss_vote_user_vote_sortable']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['ss_vote_user_vote_sortable']['field'] = 'ss_vote_user_vote_sortable';
  $handler->display->display_options['sorts']['ss_vote_user_vote_sortable']['expose']['label'] = 'ss_vote_user_vote_sortable';
  /* Sortierkriterien: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['sorts']['ss_field_user_lname']['id'] = 'ss_field_user_lname';
  $handler->display->display_options['sorts']['ss_field_user_lname']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['ss_field_user_lname']['field'] = 'ss_field_user_lname';
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'vote';
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keyword']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['keyword']['expose']['label'] = 'Suche';
  $handler->display->display_options['filters']['keyword']['expose']['operator'] = 'keyword_op';
  $handler->display->display_options['filters']['keyword']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['keyword']['expose']['remember_roles'] = array(
    2 => 0,
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    40118511 => 0,
  );
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['ss_vote_user_party']['id'] = 'ss_vote_user_party';
  $handler->display->display_options['filters']['ss_vote_user_party']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['ss_vote_user_party']['field'] = 'ss_vote_user_party';
  $handler->display->display_options['filters']['ss_vote_user_party']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ss_vote_user_party']['expose']['operator_id'] = 'ss_vote_user_party_op';
  $handler->display->display_options['filters']['ss_vote_user_party']['expose']['label'] = 'ss_vote_user_party';
  $handler->display->display_options['filters']['ss_vote_user_party']['expose']['operator'] = 'ss_vote_user_party_op';
  $handler->display->display_options['filters']['ss_vote_user_party']['expose']['identifier'] = 'ss_vote_user_party';
  $handler->display->display_options['filters']['ss_vote_user_party']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['ss_vote_user_party']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['ss_vote_user_party']['group_info']['label'] = 'Partei';
  $handler->display->display_options['filters']['ss_vote_user_party']['group_info']['identifier'] = 'ss_vote_user_party';
  $handler->display->display_options['filters']['ss_vote_user_party']['group_info']['default_group_multiple'] = array(
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['filters']['ss_vote_user_party']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'CDU',
      'operator' => '=',
      'value' => 'CDU',
    ),
    2 => array(
      'title' => 'CSU',
      'operator' => '=',
      'value' => 'CSU',
    ),
    3 => array(
      'title' => 'SPD',
      'operator' => '=',
      'value' => 'SPD',
    ),
    4 => array(
      'title' => 'DIE LINKE',
      'operator' => '=',
      'value' => '"DIE LINKE"',
    ),
    5 => array(
      'title' => 'DIE GRÜNEN',
      'operator' => '=',
      'value' => '"DIE GRÜNEN"',
    ),
    6 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['id'] = 'ss_vote_user_vote_text';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['field'] = 'ss_vote_user_vote_text';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['expose']['operator_id'] = 'ss_vote_user_vote_text_op';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['expose']['label'] = 'ss_vote_user_vote_text';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['expose']['operator'] = 'ss_vote_user_vote_text_op';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['expose']['identifier'] = 'ss_vote_user_vote_text';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['group_info']['label'] = 'Stimme';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['group_info']['identifier'] = 'ss_vote_user_vote_text';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['group_info']['default_group_multiple'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'dafür gestimmt',
      'operator' => '=',
      'value' => 'yes',
    ),
    2 => array(
      'title' => 'dagegen gestimmt',
      'operator' => '=',
      'value' => 'no',
    ),
    3 => array(
      'title' => 'enthalten',
      'operator' => '=',
      'value' => 'abstain',
    ),
    4 => array(
      'title' => 'nicht beteiligt',
      'operator' => '=',
      'value' => 'no-show',
    ),
  );
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['ss_vote_user_id']['id'] = 'ss_vote_user_id';
  $handler->display->display_options['filters']['ss_vote_user_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['ss_vote_user_id']['field'] = 'ss_vote_user_id';
  $handler->display->display_options['filters']['ss_vote_user_id']['operator'] = 'word';
  $handler->display->display_options['filters']['ss_vote_user_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ss_vote_user_id']['expose']['operator_id'] = 'ss_vote_user_id_op';
  $handler->display->display_options['filters']['ss_vote_user_id']['expose']['label'] = 'user_id_filter';
  $handler->display->display_options['filters']['ss_vote_user_id']['expose']['operator'] = 'ss_vote_user_id_op';
  $handler->display->display_options['filters']['ss_vote_user_id']['expose']['identifier'] = 'user_id_filter';
  $handler->display->display_options['filters']['ss_vote_user_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    40118511 => 0,
    29859578 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'petitionen/suche/%';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['value'] = 'vote';
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keyword']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['keyword']['expose']['label'] = 'Suche';
  $handler->display->display_options['filters']['keyword']['expose']['operator'] = 'keyword_op';
  $handler->display->display_options['filters']['keyword']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['keyword']['expose']['remember_roles'] = array(
    2 => 0,
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    40118511 => 0,
  );
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['ss_vote_user_party']['id'] = 'ss_vote_user_party';
  $handler->display->display_options['filters']['ss_vote_user_party']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['ss_vote_user_party']['field'] = 'ss_vote_user_party';
  $handler->display->display_options['filters']['ss_vote_user_party']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ss_vote_user_party']['expose']['operator_id'] = 'ss_vote_user_party_op';
  $handler->display->display_options['filters']['ss_vote_user_party']['expose']['label'] = 'ss_vote_user_party';
  $handler->display->display_options['filters']['ss_vote_user_party']['expose']['operator'] = 'ss_vote_user_party_op';
  $handler->display->display_options['filters']['ss_vote_user_party']['expose']['identifier'] = 'ss_vote_user_party';
  $handler->display->display_options['filters']['ss_vote_user_party']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['ss_vote_user_party']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['ss_vote_user_party']['group_info']['label'] = 'Partei';
  $handler->display->display_options['filters']['ss_vote_user_party']['group_info']['identifier'] = 'ss_vote_user_party';
  $handler->display->display_options['filters']['ss_vote_user_party']['group_info']['default_group_multiple'] = array(
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['filters']['ss_vote_user_party']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'CDU',
      'operator' => '=',
      'value' => 'CDU',
    ),
    2 => array(
      'title' => 'CSU',
      'operator' => '=',
      'value' => 'CSU',
    ),
    3 => array(
      'title' => 'SPD',
      'operator' => '=',
      'value' => 'SPD',
    ),
    4 => array(
      'title' => 'DIE LINKE',
      'operator' => '=',
      'value' => '"DIE LINKE"',
    ),
    5 => array(
      'title' => 'DIE GRÜNEN',
      'operator' => '=',
      'value' => '"DIE GRÜNEN"',
    ),
    6 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['id'] = 'ss_vote_user_vote_text';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['field'] = 'ss_vote_user_vote_text';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['expose']['operator_id'] = 'ss_vote_user_vote_text_op';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['expose']['label'] = 'ss_vote_user_vote_text';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['expose']['operator'] = 'ss_vote_user_vote_text_op';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['expose']['identifier'] = 'ss_vote_user_vote_text';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['group_info']['label'] = 'Stimme';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['group_info']['identifier'] = 'ss_vote_user_vote_text';
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['group_info']['default_group_multiple'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['ss_vote_user_vote_text']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'dafür gestimmt',
      'operator' => '=',
      'value' => 'yes',
    ),
    2 => array(
      'title' => 'dagegen gestimmt',
      'operator' => '=',
      'value' => 'no',
    ),
    3 => array(
      'title' => 'enthalten',
      'operator' => '=',
      'value' => 'abstain',
    ),
    4 => array(
      'title' => 'nicht beteiligt',
      'operator' => '=',
      'value' => 'no-show',
    ),
  );
  /* Filterkriterium: Beschädigte/fehlende Behandlungsroutine */
  $handler->display->display_options['filters']['sm_field_vote_node']['id'] = 'sm_field_vote_node';
  $handler->display->display_options['filters']['sm_field_vote_node']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['sm_field_vote_node']['field'] = 'sm_field_vote_node';
  $handler->display->display_options['filters']['sm_field_vote_node']['operator'] = 'allwords';
  $handler->display->display_options['filters']['sm_field_vote_node']['value'] = '*51914*';
  $handler->display->display_options['block_description'] = 'PW Vote Search Block';

  /* Display: Block Polls */
  $handler = $view->new_display('block', 'Block Polls', 'block_2');
  $handler->display->display_options['block_description'] = 'PW Vote Search Block';
  $translatables['pw_vote_search'] = array(
    t('Master'),
    t('Petitionscheck-Suche'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Wählen Sie eine beliebige Filter und klicken Sie auf Anwenden, um Ergebnisse zu sehen'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('zurück'),
    t('weiter'),
    t('letzte Seite »'),
    t('Weitere Positionen laden'),
    t('<div class="messages warning">Zu Ihrer Auswahl wurden keine Ergebnisse gefunden.</div>'),
    t('Name'),
    t('Partei'),
    t('Petition'),
    t('Begründung (kurz)'),
    t('Begründung'),
    t('User Image URI'),
    t('Drupal-Name'),
    t('Stimme'),
    t('Beschädigte Behandlungsroutine apachesolr__solr.sm_field_vote_node'),
    t('Nachname'),
    t('Beschädigte Behandlungsroutine apachesolr__solr.ss_vote_user_vote_sortable'),
    t('Beschädigte Behandlungsroutine apachesolr__solr.ds_created'),
    t('Beschädigte Behandlungsroutine apachesolr__solr.ss_vote_user_answers'),
    t('Beschädigte Behandlungsroutine apachesolr__solr.ss_vote_user_gender'),
    t('Beschädigte Behandlungsroutine apachesolr__solr.ss_vote_user_questions'),
    t('Beschädigte Behandlungsroutine apachesolr__solr.entity_id'),
    t('Beschädigte Behandlungsroutine apachesolr__solr.is_uid'),
    t('Beschädigte Behandlungsroutine apachesolr__solr.ss_vote_user_id'),
    t('ss_vote_user_vote_sortable'),
    t('Suche'),
    t('ss_vote_user_party'),
    t('ss_vote_user_vote_text'),
    t('user_id_filter'),
    t('Page'),
    t('Block'),
    t('PW Vote Search Block'),
    t('Block Polls'),
  );
  $export['pw_vote_search'] = $view;

  return $export;
}
