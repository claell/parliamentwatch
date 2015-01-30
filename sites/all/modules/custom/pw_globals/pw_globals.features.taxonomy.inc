<?php
/**
 * @file
 * pw_globals.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pw_globals_taxonomy_default_vocabularies() {
  return array(
    'area_codex' => array(
      'name' => 'Area Codes',
      'machine_name' => 'area_codex',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '0',
    ),
    'constituency' => array(
      'name' => 'Constituency',
      'machine_name' => 'constituency',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '1',
    ),
    'election_list' => array(
      'name' => 'List',
      'machine_name' => 'election_list',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '1',
    ),
    'electoral_region' => array(
      'name' => 'Electoral Region',
      'machine_name' => 'electoral_region',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '1',
    ),
    'parliaments' => array(
      'name' => 'Parliaments',
      'machine_name' => 'parliaments',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '0',
    ),
    'party' => array(
      'name' => 'Party',
      'machine_name' => 'party',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '1',
    ),
    'political_roles' => array(
      'name' => 'Political Roles',
      'machine_name' => 'political_roles',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '1',
    ),
    'pw_widget_values' => array(
      'name' => 'PW Widget Values',
      'machine_name' => 'pw_widget_values',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '0',
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '0',
    ),
  );
}
