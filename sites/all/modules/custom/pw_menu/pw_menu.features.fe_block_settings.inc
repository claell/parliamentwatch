<?php
/**
 * @file
 * pw_menu.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function pw_menu_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['tb_megamenu-menu-main-menu-de'] = array(
    'cache' => -1,
    'css_class' => 'desktop-only small',
    'custom' => '0',
    'delta' => 'menu-main-menu-de',
    'module' => 'tb_megamenu',
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
        'region' => 'menu',
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
    'title' => '<none>',
    'visibility' => '0',
  );

  return $export;
}
