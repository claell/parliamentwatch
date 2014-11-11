<?php
/**
 * @file
 * pw_sidejobs.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pw_sidejobs_taxonomy_default_vocabularies() {
  return array(
    'sidejob_jobs' => array(
      'name' => 'Sidejob Jobs',
      'machine_name' => 'sidejob_jobs',
      'description' => 'All Jobs relating to Sidejob',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '0',
    ),
    'sidejob_organizations' => array(
      'name' => 'Sidejob Organizations',
      'machine_name' => 'sidejob_organizations',
      'description' => 'Organizations for Content Type Sidejob',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '0',
    ),
    'sidejob_sectors' => array(
      'name' => 'Sidejob Sectors',
      'machine_name' => 'sidejob_sectors',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '0',
    ),
  );
}
