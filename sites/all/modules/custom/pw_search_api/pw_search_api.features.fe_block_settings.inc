<?php
/**
 * @file
 * pw_search_api.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function pw_search_api_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['facetapi-6LIkVo9hGpY0QNENsoc1rFvBAY2vvl91'] = array(
    'cache' => '-1',
    'css_class' => '',
    'custom' => '0',
    'delta' => '6LIkVo9hGpY0QNENsoc1rFvBAY2vvl91',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'suche/*',
    'roles' => array(),
    'themes' => array(
      'blank' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'blank',
        'weight' => '0',
      ),
      'parliamentwatch' => array(
        'region' => 'sidebar_second',
        'status' => '1',
        'theme' => 'parliamentwatch',
        'weight' => '0',
      ),
      'pw_seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'pw_seven',
        'weight' => '0',
      ),
    ),
    'title' => 'Wahlkreis',
    'visibility' => '1',
  );

  $export['facetapi-JMJyfWVTjAJO2jr2Biylawo43Py0MS4c'] = array(
    'cache' => '-1',
    'css_class' => '',
    'custom' => '0',
    'delta' => 'JMJyfWVTjAJO2jr2Biylawo43Py0MS4c',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'suche/*',
    'roles' => array(),
    'themes' => array(
      'blank' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'blank',
        'weight' => '0',
      ),
      'parliamentwatch' => array(
        'region' => 'sidebar_second',
        'status' => '1',
        'theme' => 'parliamentwatch',
        'weight' => '1',
      ),
      'pw_seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'pw_seven',
        'weight' => '0',
      ),
    ),
    'title' => 'Partei',
    'visibility' => '1',
  );

  $export['facetapi-QHQ9XNFUW6pTfzSfjKuWjYVJkxgIt1Hi'] = array(
    'cache' => '-1',
    'css_class' => '',
    'custom' => '0',
    'delta' => 'QHQ9XNFUW6pTfzSfjKuWjYVJkxgIt1Hi',
    'module' => 'facetapi',
    'node_types' => array(),
    'pages' => 'suche/*',
    'roles' => array(),
    'themes' => array(
      'blank' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'blank',
        'weight' => '0',
      ),
      'parliamentwatch' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'parliamentwatch',
        'weight' => '13',
      ),
      'pw_seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'pw_seven',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '1',
  );

  $export['search-form'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => '0',
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'blank' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'blank',
        'weight' => '1',
      ),
      'parliamentwatch' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'parliamentwatch',
        'weight' => '1',
      ),
      'pw_seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'pw_seven',
        'weight' => '1',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['views--exp-pw_search_api_main-page'] = array(
    'cache' => '-1',
    'css_class' => 'compact-form',
    'custom' => '0',
    'delta' => '-exp-pw_search_api_main-page',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'blank' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'blank',
        'weight' => '0',
      ),
      'parliamentwatch' => array(
        'region' => 'sidebar_second',
        'status' => '1',
        'theme' => 'parliamentwatch',
        'weight' => '0',
      ),
      'pw_seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'pw_seven',
        'weight' => '0',
      ),
    ),
    'title' => 'abgeordnetenwatch.de durchsuchen',
    'visibility' => '1',
  );

  $export['views-dd2cb179c08ae616789999b01178b193'] = array(
    'cache' => '-1',
    'css_class' => 'compact-form',
    'custom' => '0',
    'delta' => 'dd2cb179c08ae616789999b01178b193',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'suche/*',
    'roles' => array(),
    'themes' => array(
      'blank' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'blank',
        'weight' => '0',
      ),
      'parliamentwatch' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'parliamentwatch',
        'weight' => '12',
      ),
      'pw_seven' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'pw_seven',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '1',
  );

  $export['views-politician_search_view-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => '0',
    'delta' => 'politician_search_view-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'blank' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'blank',
        'weight' => '0',
      ),
      'parliamentwatch' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'parliamentwatch',
        'weight' => '0',
      ),
      'pw_seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'pw_seven',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  return $export;
}
