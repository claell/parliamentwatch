<?php
/**
 * @file
 * pw_profiles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pw_profiles_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function pw_profiles_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function pw_profiles_node_info() {
  $items = array(
    'calendar_entry' => array(
      'name' => t('Calendar Entry'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_rdf_default_mappings().
 */
function pw_profiles_rdf_default_mappings() {
  $schemaorg = array();

  // Exported RDF mapping: calendar_entry
  $schemaorg['node']['calendar_entry'] = array(
    'rdftype' => array(
      0 => 'schema:Event',
      1 => 'sioc:Item',
      2 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'schema:name',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'schema:summary',
        1 => 'schema:description',
        2 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'schema:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'field_calendar_entry_address' => array(
      'predicates' => array(
        0 => 'schema:address',
      ),
    ),
    'url' => array(
      'predicates' => array(
        0 => 'schema:url',
      ),
      'type' => 'rel',
    ),
    'field_calendar_entry_date' => array(
      'predicates' => array(
        0 => 'schema:startDate',
      ),
    ),
  );

  // Exported RDF mapping: user
  $schemaorg['user']['user'] = array(
    'rdftype' => array(
      0 => 'schema:Person',
      1 => 'sioc:UserAccount',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'schema:name',
      ),
    ),
    'homepage' => array(
      'predicates' => array(
        0 => 'foaf:page',
      ),
      'type' => 'rel',
    ),
    'field_user_public_mail' => array(
      'predicates' => array(
        0 => 'schema:email',
      ),
    ),
    'url' => array(
      'predicates' => array(
        0 => 'schema:url',
      ),
      'type' => 'rel',
    ),
    'field_user_party' => array(
      'predicates' => array(
        0 => 'schema:memberOf',
      ),
      'type' => 'rel',
    ),
    'field_user_address' => array(
      'predicates' => array(
        0 => 'schema:address',
      ),
    ),
    'field_user_birthday' => array(
      'predicates' => array(
        0 => 'schema:birthDate',
      ),
    ),
    'field_user_fname' => array(
      'predicates' => array(
        0 => 'schema:givenName',
      ),
    ),
    'field_user_lname' => array(
      'predicates' => array(
        0 => 'schema:familyName',
      ),
    ),
    'field_user_phone' => array(
      'predicates' => array(
        0 => 'schema:telephone',
      ),
    ),
    'field_user_job_skills' => array(
      'predicates' => array(
        0 => 'schema:jobTitle',
      ),
    ),
    'field_user_title' => array(
      'predicates' => array(
        0 => 'schema:honorificSuffix',
      ),
    ),
    'field_user_list' => array(
      'predicates' => array(),
      'type' => 'rel',
    ),
    'field_user_constituency' => array(
      'predicates' => array(),
      'type' => 'rel',
    ),
    'field_user_parliament' => array(
      'predicates' => array(
        0 => 'schema:memberOf',
      ),
      'type' => 'rel',
    ),
    'field_user_gender' => array(
      'predicates' => array(
        0 => 'schema:gender',
      ),
    ),
    'field_user_picture' => array(
      'predicates' => array(
        0 => 'schema:image',
      ),
      'type' => 'rel',
    ),
    'field_user_about' => array(
      'predicates' => array(
        0 => 'schema:about',
      ),
    ),
  );

  return $schemaorg;
}
