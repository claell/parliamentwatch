<?php
/**
 * @file
 * pw_committees.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pw_committees_taxonomy_default_vocabularies() {
  return array(
    'committee' => array(
      'name' => 'Committee',
      'machine_name' => 'committee',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '1',
    ),
    'committee_types' => array(
      'name' => 'Committee Types',
      'machine_name' => 'committee_types',
      'description' => 'types of committees for tagging committees',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '1',
    ),
  );
}
