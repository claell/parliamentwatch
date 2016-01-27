<?php
/**
 * @file
 * pw_gdata_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function pw_gdata_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_importer';
  $feeds_importer->config = array(
    'name' => 'CSV Importer',
    'description' => 'bulk updater for imported profiles',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => 0,
          51622513 => 0,
          181527986 => 0,
          140336230 => 0,
          185431326 => 0,
          178386088 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'county',
            'target' => 'field_user_address:administrative_area',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'system_uuid',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'system_username',
            'target' => 'name',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'country_default',
            'target' => 'field_user_address:country',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'list_position',
            'target' => 'field_user_list_position',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'city',
            'target' => 'field_user_address:locality',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'postal_code',
            'target' => 'field_user_address:postal_code',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['csv_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_constituency_importer';
  $feeds_importer->config = array(
    'name' => 'GData Constituency Importer',
    'description' => 'Imports Constituencies from GData Spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'parliament',
          'xpathparser:1' => 'constituency',
          'xpathparser:3' => 'constituencynumber',
          'xpathparser:4' => 'systemuuid',
          'xpathparser:5' => 'systemuuid',
          'xpathparser:6' => 'areacodes',
          'xpathparser:7' => 'concat(parliament,\'-\',state)',
          'xpathparser:8' => 'areacodesdescription',
          'xpathparser:9' => 'electoralregion',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 1,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'field_parliament',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'name',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_constituency_nr',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:5',
            'target' => 'guid',
            'unique' => 1,
          ),
          5 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_constituency_area_codes',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          6 => array(
            'source' => 'xpathparser:7',
            'target' => 'parentguid',
            'unique' => 0,
          ),
          7 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_constituency_ac_descriptor',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_electoral_region',
            'term_search' => '1',
            'autocreate' => 0,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'constituency',
        'vocabulary' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_constituency_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_elected_profiles';
  $feeds_importer->config = array(
    'name' => 'GData Profiles After Election Updater',
    'description' => 'Sets results after elections. Also overwrites all email addresses to reduce data.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'systemuuid',
          'xpathparser:2' => 'constituencywon',
          'xpathparser:3' => 'listwon',
          'xpathparser:4' => 'constituencyresult',
          'xpathparser:6' => 'systemroles',
          'xpathparser:7' => 'systemroles',
          'xpathparser:8' => 'list',
          'xpathparser:9' => 'listposition',
          'xpathparser:10' => 'parliament',
          'xpathparser:12' => 'systemuuid',
          'xpathparser:13' => 'email',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 1,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => 0,
          51622513 => 0,
          181527986 => 0,
          140336230 => 0,
          185431326 => 0,
          178386088 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_user_constituency_won',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_user_list_won',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_user_election_result',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:6',
            'target' => 'roles',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_user_roles_for_view_mode_s',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_user_list',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          7 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_user_list_position',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          8 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_user_parliament',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:12',
            'target' => 'name',
            'unique' => 1,
          ),
          10 => array(
            'source' => 'xpathparser:13',
            'target' => 'mail',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_elected_profiles'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_electoral_region_importer';
  $feeds_importer->config = array(
    'name' => 'GData Electoral Region Importer',
    'description' => 'Imports Electoral Regions from GData Spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => '',
        'auto_scheme' => 'http',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'systemuuid',
          'xpathparser:1' => 'parliament',
          'xpathparser:2' => 'electoralregion',
          'xpathparser:3' => 'notes',
          'xpathparser:4' => 'systemuuid',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_parliament',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'description',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'electoral_region',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_electoral_region_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_lists_importer';
  $feeds_importer->config = array(
    'name' => 'GData Lists Importer',
    'description' => 'Imports Lists from GData Spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'systemuuid',
          'xpathparser:1' => 'parliament',
          'xpathparser:2' => 'electoralregion',
          'xpathparser:3' => 'list',
          'xpathparser:4' => 'systemuuid',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_parliament',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_electoral_region',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          3 => array(
            'source' => 'xpathparser:3',
            'target' => 'name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'election_list',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_lists_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_parliaments_importer';
  $feeds_importer->config = array(
    'name' => 'GData Parliaments Importer',
    'description' => 'Imports Parliaments from GData Spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:3' => 'systemuuid',
          'xpathparser:0' => 'parliament',
          'xpathparser:1' => 'dateelection',
          'xpathparser:2' => 'dateperiodstart',
          'xpathparser:4' => 'dateperiodend',
          'xpathparser:5' => 'systemuuid',
          'xpathparser:6' => 'premiumprice',
        ),
        'rawXML' => array(
          'xpathparser:3' => 0,
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
          'xpathparser:4' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 1,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:3' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
            'xpathparser:4' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:3',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:0',
            'target' => 'name',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'xpathparser:1',
            'target' => 'field_parliament_election:start',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:2',
            'target' => 'field_parliament_valid:start',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:4',
            'target' => 'field_parliament_valid:end',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:5',
            'target' => 'guid',
            'unique' => 1,
          ),
          6 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_premium_profile_price',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'parliaments',
        'vocabulary' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_parliaments_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_party_importer';
  $feeds_importer->config = array(
    'name' => 'GData Party Importer',
    'description' => 'Imports Parties from GData Spreadsheet',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'systemuuid',
          'xpathparser:1' => 'party',
          'xpathparser:2' => 'systemuuid',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:2' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 1,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:2' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'name',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'xpathparser:2',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'party',
        'vocabulary' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_party_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_profiles_importer_v2';
  $feeds_importer->config = array(
    'name' => 'GData Profiles Importer v2',
    'description' => 'Imports Profiles from GData Spreadsheet (v2)',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'systemuuid',
          'xpathparser:2' => 'email',
          'xpathparser:3' => 'systemuuid',
          'xpathparser:4' => 'systemroles',
          'xpathparser:7' => 'nameprefix',
          'xpathparser:8' => 'birthday',
          'xpathparser:9' => 'birthdayend',
          'xpathparser:10' => 'gender',
          'xpathparser:11' => 'firstname',
          'xpathparser:12' => 'lastname',
          'xpathparser:13' => 'publicmail',
          'xpathparser:14' => 'phone',
          'xpathparser:15' => 'county',
          'xpathparser:16' => 'residence',
          'xpathparser:17' => 'postalcode',
          'xpathparser:18' => 'childs',
          'xpathparser:19' => 'marriagestatus',
          'xpathparser:20' => 'education',
          'xpathparser:21' => 'profession',
          'xpathparser:22' => 'politicalroles',
          'xpathparser:23' => 'txtpoliticalgoals',
          'xpathparser:24' => 'party',
          'xpathparser:25' => 'parliament',
          'xpathparser:26' => 'constituency',
          'xpathparser:27' => 'listposition',
          'xpathparser:28' => 'constituencyresult',
          'xpathparser:29' => 'pictureurl',
          'xpathparser:30' => 'picturecopyright',
          'xpathparser:31' => 'txtabout',
          'xpathparser:32' => 'twitteraccount',
          'xpathparser:33' => 'externalurl',
          'xpathparser:34' => 'facebookurl',
          'xpathparser:35' => 'systemroles',
          'xpathparser:36' => 'list',
          'xpathparser:37' => 'fraction',
          'xpathparser:38' => 'validstart',
          'xpathparser:39' => 'validend',
          'xpathparser:40' => 'datejoined',
          'xpathparser:41' => 'dateretired',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
          'xpathparser:4' => 0,
          'xpathparser:7' => 0,
          'xpathparser:8' => 0,
          'xpathparser:9' => 0,
          'xpathparser:10' => 0,
          'xpathparser:11' => 0,
          'xpathparser:12' => 0,
          'xpathparser:13' => 0,
          'xpathparser:14' => 0,
          'xpathparser:15' => 0,
          'xpathparser:16' => 0,
          'xpathparser:17' => 0,
          'xpathparser:18' => 0,
          'xpathparser:19' => 0,
          'xpathparser:20' => 0,
          'xpathparser:21' => 0,
          'xpathparser:22' => 0,
          'xpathparser:23' => 0,
          'xpathparser:24' => 0,
          'xpathparser:25' => 0,
          'xpathparser:26' => 0,
          'xpathparser:27' => 0,
          'xpathparser:28' => 0,
          'xpathparser:29' => 0,
          'xpathparser:30' => 0,
          'xpathparser:31' => 0,
          'xpathparser:32' => 0,
          'xpathparser:33' => 0,
          'xpathparser:34' => 0,
          'xpathparser:35' => 0,
          'xpathparser:36' => 0,
          'xpathparser:37' => 0,
          'xpathparser:38' => 0,
          'xpathparser:39' => 0,
          'xpathparser:40' => 0,
          'xpathparser:41' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 1,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
            'xpathparser:4' => 0,
            'xpathparser:7' => 0,
            'xpathparser:8' => 0,
            'xpathparser:9' => 0,
            'xpathparser:10' => 0,
            'xpathparser:11' => 0,
            'xpathparser:12' => 0,
            'xpathparser:13' => 0,
            'xpathparser:14' => 0,
            'xpathparser:15' => 0,
            'xpathparser:16' => 0,
            'xpathparser:17' => 0,
            'xpathparser:18' => 0,
            'xpathparser:19' => 0,
            'xpathparser:20' => 0,
            'xpathparser:21' => 0,
            'xpathparser:22' => 0,
            'xpathparser:23' => 0,
            'xpathparser:24' => 0,
            'xpathparser:25' => 0,
            'xpathparser:26' => 0,
            'xpathparser:27' => 0,
            'xpathparser:28' => 0,
            'xpathparser:29' => 0,
            'xpathparser:30' => 0,
            'xpathparser:31' => 0,
            'xpathparser:32' => 0,
            'xpathparser:33' => 0,
            'xpathparser:34' => 0,
            'xpathparser:35' => 0,
            'xpathparser:36' => 0,
            'xpathparser:37' => 0,
            'xpathparser:38' => 0,
            'xpathparser:39' => 0,
            'xpathparser:40' => 0,
            'xpathparser:41' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => 0,
          51622513 => 0,
          181527986 => 0,
          140336230 => 0,
          185431326 => 0,
          178386088 => 0,
          29859578 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:2',
            'target' => 'mail',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'xpathparser:3',
            'target' => 'uuid:uuid',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:4',
            'target' => 'roles',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:7',
            'target' => 'field_user_title',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'xpathparser:8',
            'target' => 'field_user_birthday:start',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'xpathparser:9',
            'target' => 'field_user_birthday:end',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'xpathparser:10',
            'target' => 'field_user_gender',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'xpathparser:11',
            'target' => 'field_user_fname',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'xpathparser:12',
            'target' => 'field_user_lname',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'xpathparser:13',
            'target' => 'field_user_public_mail',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'xpathparser:14',
            'target' => 'field_user_phone',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'Blank source 1',
            'target' => 'field_user_address:country',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'xpathparser:15',
            'target' => 'field_user_address:administrative_area',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'xpathparser:16',
            'target' => 'field_user_address:locality',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'xpathparser:17',
            'target' => 'field_user_address:postal_code',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'xpathparser:18',
            'target' => 'field_user_childs',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'xpathparser:19',
            'target' => 'field_user_marriage_status',
            'unique' => FALSE,
          ),
          18 => array(
            'source' => 'xpathparser:20',
            'target' => 'field_user_education',
            'unique' => FALSE,
          ),
          19 => array(
            'source' => 'xpathparser:21',
            'target' => 'field_user_job_skills',
            'unique' => FALSE,
          ),
          20 => array(
            'source' => 'xpathparser:22',
            'target' => 'field_user_political_roles',
            'unique' => FALSE,
          ),
          21 => array(
            'source' => 'xpathparser:23',
            'target' => 'field_user_political_goals',
            'unique' => FALSE,
          ),
          22 => array(
            'source' => 'xpathparser:24',
            'target' => 'field_user_party',
            'term_search' => '0',
            'autocreate' => 0,
          ),
          23 => array(
            'source' => 'xpathparser:25',
            'target' => 'field_user_parliament',
            'unique' => FALSE,
          ),
          24 => array(
            'source' => 'xpathparser:26',
            'target' => 'field_user_constituency',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          25 => array(
            'source' => 'xpathparser:27',
            'target' => 'field_user_list_position',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          26 => array(
            'source' => 'xpathparser:28',
            'target' => 'field_user_election_result',
            'unique' => FALSE,
          ),
          27 => array(
            'source' => 'xpathparser:29',
            'target' => 'field_user_picture',
            'unique' => FALSE,
          ),
          28 => array(
            'source' => 'xpathparser:30',
            'target' => 'field_user_picture_copyright',
            'unique' => FALSE,
          ),
          29 => array(
            'source' => 'xpathparser:31',
            'target' => 'field_user_about',
            'unique' => FALSE,
          ),
          30 => array(
            'source' => 'xpathparser:32',
            'target' => 'field_user_twitter_account',
            'unique' => FALSE,
          ),
          31 => array(
            'source' => 'xpathparser:33',
            'target' => 'field_user_external_url:url',
            'unique' => FALSE,
          ),
          32 => array(
            'source' => 'xpathparser:34',
            'target' => 'field_user_links_more:url',
            'unique' => FALSE,
          ),
          33 => array(
            'source' => 'xpathparser:35',
            'target' => 'field_user_roles_for_view_mode_s',
            'unique' => FALSE,
          ),
          34 => array(
            'source' => 'xpathparser:36',
            'target' => 'field_user_list',
            'term_search' => '1',
            'autocreate' => 0,
          ),
          35 => array(
            'source' => 'Blank source 2',
            'target' => 'name',
            'unique' => 1,
          ),
          36 => array(
            'source' => 'xpathparser:37',
            'target' => 'field_user_fraction',
            'term_search' => '0',
            'autocreate' => 1,
          ),
          37 => array(
            'source' => 'xpathparser:40',
            'target' => 'field_user_joined:start',
            'unique' => FALSE,
          ),
          38 => array(
            'source' => 'xpathparser:41',
            'target' => 'field_user_retired:start',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'filtered_html',
        'skip_hash_check' => 1,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_profiles_importer_v2'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_profiles_updater';
  $feeds_importer->config = array(
    'name' => 'GData Profiles Role Updater',
    'description' => '[deprecated, please use gdata_elected_profiles instead] Updates Profiles primarily to assign role Deputy after elections',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'systemuuid',
          'xpathparser:1' => 'systemuuid',
          'xpathparser:5' => 'systemroles',
          'xpathparser:6' => 'systemroles',
          'xpathparser:7' => 'email',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:5' => 0,
          'xpathparser:6' => 0,
          'xpathparser:7' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 0,
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:5' => 0,
            'xpathparser:6' => 0,
            'xpathparser:7' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => 0,
          51622513 => 0,
          181527986 => 0,
          140336230 => 0,
          185431326 => 0,
          178386088 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'name',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'xpathparser:5',
            'target' => 'roles',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'xpathparser:6',
            'target' => 'field_user_roles_for_view_mode_s',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'xpathparser:7',
            'target' => 'mail',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_profiles_updater'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_states_importer';
  $feeds_importer->config = array(
    'name' => 'GData States Importer',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:0' => 'parliament',
          'xpathparser:1' => 'state',
          'xpathparser:5' => 'concat(parliament,\'-\',state)',
        ),
        'rawXML' => array(
          'xpathparser:0' => 0,
          'xpathparser:1' => 0,
          'xpathparser:5' => 0,
        ),
        'context' => '//row[state!=\'\']',
        'exp' => array(
          'errors' => 1,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:0' => 0,
            'xpathparser:1' => 0,
            'xpathparser:5' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:0',
            'target' => 'field_parliament',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'xpathparser:1',
            'target' => 'name',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'xpathparser:5',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'constituency',
        'vocabulary' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_states_importer'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'gdata_subject_importer';
  $feeds_importer->config = array(
    'name' => 'GData Subject Importer',
    'description' => 'imports subjects for question form',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsXPathParserXML',
      'config' => array(
        'sources' => array(
          'xpathparser:2' => 'subject',
          'xpathparser:3' => 'parliament',
        ),
        'rawXML' => array(
          'xpathparser:2' => 0,
          'xpathparser:3' => 0,
        ),
        'context' => '//row',
        'exp' => array(
          'errors' => 0,
          'tidy' => 0,
          'tidy_encoding' => 'UTF8',
          'debug' => array(
            'context' => 0,
            'xpathparser:2' => 0,
            'xpathparser:3' => 0,
          ),
        ),
        'allow_override' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'xpathparser:2',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'xpathparser:3',
            'target' => 'field_parliament',
            'term_search' => '1',
            'autocreate' => 0,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'dialogue_topics',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['gdata_subject_importer'] = $feeds_importer;

  return $export;
}
