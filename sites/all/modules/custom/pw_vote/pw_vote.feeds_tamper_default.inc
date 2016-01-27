<?php
/**
 * @file
 * pw_vote.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function pw_vote_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_vote_importer-blank_source_1-default_value';
  $feeds_tamper->importer = 'gdata_vote_importer';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value';
  $export['gdata_vote_importer-blank_source_1-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_vote_importer-xpathparser_10-check_uuid_exists';
  $feeds_tamper->importer = 'gdata_vote_importer';
  $feeds_tamper->source = 'xpathparser:10';
  $feeds_tamper->plugin_id = 'check_uuid_exists';
  $feeds_tamper->settings = array(
    'entity_type' => 'user',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Checks if UUID exists';
  $export['gdata_vote_importer-xpathparser_10-check_uuid_exists'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_vote_importer-xpathparser_10-required';
  $feeds_tamper->importer = 'gdata_vote_importer';
  $feeds_tamper->source = 'xpathparser:10';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Pflichtfeld';
  $export['gdata_vote_importer-xpathparser_10-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_vote_importer-xpathparser_11-check_uuid_exists';
  $feeds_tamper->importer = 'gdata_vote_importer';
  $feeds_tamper->source = 'xpathparser:11';
  $feeds_tamper->plugin_id = 'check_uuid_exists';
  $feeds_tamper->settings = array(
    'entity_type' => 'node',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Checks if UUID exists';
  $export['gdata_vote_importer-xpathparser_11-check_uuid_exists'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_vote_importer-xpathparser_11-required';
  $feeds_tamper->importer = 'gdata_vote_importer';
  $feeds_tamper->source = 'xpathparser:11';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Pflichtfeld';
  $export['gdata_vote_importer-xpathparser_11-required'] = $feeds_tamper;

  return $export;
}
