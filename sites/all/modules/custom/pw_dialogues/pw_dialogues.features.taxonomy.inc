<?php
/**
 * @file
 * pw_dialogues.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function pw_dialogues_taxonomy_default_vocabularies() {
  return array(
    'dialogue_tags' => array(
      'name' => 'Dialogue tags',
      'machine_name' => 'dialogue_tags',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '0',
    ),
    'dialogue_topics' => array(
      'name' => 'Dialogue topics',
      'machine_name' => 'dialogue_topics',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '1',
    ),
  );
}
