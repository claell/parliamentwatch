<?php
/**
 * @file
 * pw_search_api.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function pw_search_api_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@politician_index::field_user_constituency';
  $facet->searcher = 'search_api@politician_index';
  $facet->realm = '';
  $facet->facet = 'field_user_constituency';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(),
    ),
    'facet_mincount' => '2',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'wahlkreis',
    'pretty_paths_taxonomy_pathauto' => 1,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'constituency',
  );
  $export['search_api@politician_index::field_user_constituency'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@politician_index::field_user_parliament';
  $facet->searcher = 'search_api@politician_index';
  $facet->realm = '';
  $facet->facet = 'field_user_parliament';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '3',
    'dependencies' => array(
      'roles' => array(),
      'facets' => array(),
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '1',
    'query_type' => 'term',
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'parlament',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'parliaments',
  );
  $export['search_api@politician_index::field_user_parliament'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@politician_index::field_user_parliament:name';
  $facet->searcher = 'search_api@politician_index';
  $facet->realm = '';
  $facet->facet = 'field_user_parliament:name';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 1,
  );
  $export['search_api@politician_index::field_user_parliament:name'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@politician_index::field_user_party';
  $facet->searcher = 'search_api@politician_index';
  $facet->realm = '';
  $facet->facet = 'field_user_party';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '50',
    'dependencies' => array(
      'facets' => array(),
      'force_deactivation' => TRUE,
      'regex' => FALSE,
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'partei',
    'pretty_paths_taxonomy_pathauto' => 1,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'party',
  );
  $export['search_api@politician_index::field_user_party'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@politician_index::field_user_political_roles';
  $facet->searcher = 'search_api@politician_index';
  $facet->realm = '';
  $facet->facet = 'field_user_political_roles';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '1',
    'flatten' => '1',
    'query_type' => 'term',
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@politician_index::field_user_political_roles'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@politician_index::im_field_user_constituency';
  $facet->searcher = 'search_api@politician_index';
  $facet->realm = '';
  $facet->facet = 'im_field_user_constituency';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'roles' => array(),
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => 0,
    'flatten' => '1',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'wahlkreis',
    'pretty_paths_taxonomy_pathauto' => 1,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'constituency',
  );
  $export['search_api@politician_index::im_field_user_constituency'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@politician_index:block:field_user_lname';
  $facet->searcher = 'search_api@politician_index';
  $facet->realm = 'block';
  $facet->facet = 'field_user_lname';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@politician_index:block:field_user_lname'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@politician_index:block:field_user_parliament';
  $facet->searcher = 'search_api@politician_index';
  $facet->realm = 'block';
  $facet->facet = 'field_user_parliament';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_tab_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-49',
      ),
      'rewrite_items' => array(
        'status' => 0,
        'weight' => '-47',
      ),
      'rewrite_items2' => array(
        'status' => 1,
        'weight' => '-43',
      ),
    ),
    'active_sorts' => array(
      'display' => 'display',
      'count' => 'count',
      'active' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'display' => '-49',
      'count' => '-48',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'display' => '4',
      'count' => '3',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 1,
    'show_all' => 0,
    'show_count' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'managed_content',
    ),
    'submit_realm' => 'Speichern und zur Bereichskonfiguration zurückgehen',
    'exclude' => '',
    'regex' => 0,
    'show_minimum_items' => 2,
    'default_option_label' => '',
    'submit_page' => '',
  );
  $export['search_api@politician_index:block:field_user_parliament'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@politician_index:block:field_user_parliament:name';
  $facet->searcher = 'search_api@politician_index';
  $facet->realm = 'block';
  $facet->facet = 'field_user_parliament:name';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_tab_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'show_all' => 1,
    'show_count' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'managed_content',
    ),
    'submit_realm' => 'Speichern und zur Bereichskonfiguration zurückgehen',
  );
  $export['search_api@politician_index:block:field_user_parliament:name'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@politician_index:block:field_user_party';
  $facet->searcher = 'search_api@politician_index';
  $facet->realm = 'block';
  $facet->facet = 'field_user_party';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(),
    'active_sorts' => array(
      'display' => 'display',
      'count' => 'count',
      'active' => 0,
      'natural' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-48',
      'display' => '-49',
      'natural' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'natural' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'show_all' => 1,
    'show_count' => 1,
    'default_option_label' => '',
    'submit_page' => '',
    'empty_text' => array(
      'value' => '',
      'format' => 'managed_content',
    ),
    'submit_realm' => 'Speichern und zur Bereichskonfiguration zurückgehen',
  );
  $export['search_api@politician_index:block:field_user_party'] = $facet;

  return $export;
}
