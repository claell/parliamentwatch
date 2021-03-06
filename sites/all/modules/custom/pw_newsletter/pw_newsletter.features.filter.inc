<?php
/**
 * @file
 * pw_newsletter.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function pw_newsletter_filter_default_formats() {
  $formats = array();

  // Exported format: Newsletter.
  $formats['newsletter'] = array(
    'format' => 'newsletter',
    'name' => 'Newsletter',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'filter_htmlcorrector' => array(
        'weight' => '-50',
        'status' => '1',
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => '-49',
        'status' => '1',
        'settings' => array(
          'local_paths' => '',
          'protocol_style' => 'full',
        ),
      ),
      'media_filter' => array(
        'weight' => '-48',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => '-47',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<a> <strong><blockquote><ul><ol><li><h2><h3><div><span><p><sub><sup>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_url' => array(
        'weight' => '-43',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_autop' => array(
        'weight' => '-41',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
