<?php
/**
 * @file
 * pw_poll.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function pw_poll_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_vote_importer-xpathparser_0-required';
  $feeds_tamper->importer = 'gdata_vote_importer';
  $feeds_tamper->source = 'xpathparser:0';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Pflichtfeld';
  $export['gdata_vote_importer-xpathparser_0-required'] = $feeds_tamper;

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
  $feeds_tamper->id = 'gdata_vote_importer-xpathparser_6-required';
  $feeds_tamper->importer = 'gdata_vote_importer';
  $feeds_tamper->source = 'xpathparser:6';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Pflichtfeld';
  $export['gdata_vote_importer-xpathparser_6-required'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_vote_importer-xpathparser_8-check_uuid_exists';
  $feeds_tamper->importer = 'gdata_vote_importer';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'check_uuid_exists';
  $feeds_tamper->settings = array(
    'entity_type' => 'node',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Checks if UUID exists';
  $export['gdata_vote_importer-xpathparser_8-check_uuid_exists'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'gdata_vote_importer-xpathparser_8-required';
  $feeds_tamper->importer = 'gdata_vote_importer';
  $feeds_tamper->source = 'xpathparser:8';
  $feeds_tamper->plugin_id = 'required';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Pflichtfeld';
  $export['gdata_vote_importer-xpathparser_8-required'] = $feeds_tamper;

  return $export;
}