<?php
/**
 * @file
 * pw_blog.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function pw_blog_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blogpost|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blogpost';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'sharethis' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|blogpost|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blogpost|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blogpost';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'author_linked_to_contact_form' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => ' by ',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'sharebuttons' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
        'linked_field' => array(
          'linked' => 0,
          'destination' => '',
          'advanced' => array(
            'title' => '',
            'target' => '',
            'class' => '',
            'rel' => '',
            'text' => '',
          ),
        ),
      ),
    ),
    'sharethis' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'sharethis_horizontal' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'custom_comment_counter' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'comment-count',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
        'linked_field' => array(
          'linked' => 0,
          'destination' => '',
          'advanced' => array(
            'title' => '',
            'target' => '',
            'class' => '',
            'rel' => '',
            'text' => '',
          ),
        ),
      ),
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'comments' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'post_date' => array(
      'weight' => '3',
      'label' => 'inline',
      'format' => 'ds_post_date_date_and_time',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Posted on ',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'managed-content',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_blogpost_blogtags' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'icon-taxonomy',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_blogpost_categories' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => ' in ',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|blogpost|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blogpost|print';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blogpost';
  $ds_fieldsetting->view_mode = 'print';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '5',
      'label' => 'inline',
      'format' => 'author',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => ' von ',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'author',
        ),
      ),
    ),
    'post_date' => array(
      'weight' => '4',
      'label' => 'inline',
      'format' => 'ds_post_date_medium',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Veröffentlicht am ',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'date',
        ),
      ),
    ),
    'field_blogpost_blogtags' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-type-taxonomy-term-reference clearfix clear-both',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => '',
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
        ),
      ),
    ),
  );
  $export['node|blogpost|print'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blogpost|rss';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blogpost';
  $ds_fieldsetting->view_mode = 'rss';
  $ds_fieldsetting->settings = array(
    'node_link' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|blogpost|rss'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blogpost|search_result';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blogpost';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h4',
        'class' => 'push-bottom-s',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
        'linked_field' => array(
          'linked' => 0,
          'destination' => '',
          'advanced' => array(
            'title' => '',
            'target' => '',
            'class' => '',
            'rel' => '',
            'text' => '',
          ),
        ),
      ),
    ),
    'node_link' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Blogartikel lesen',
        'wrapper' => 'span',
        'class' => 'read-more',
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'text-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
        'linked_field' => array(
          'linked' => 0,
          'destination' => '',
          'advanced' => array(
            'title' => '',
            'target' => '',
            'class' => '',
            'rel' => '',
            'text' => '',
          ),
        ),
      ),
    ),
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_date_only_short',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'grid-2 alpha',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'arrow-item',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'search_snippet' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'push-bottom-s',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
        'linked_field' => array(
          'linked' => 0,
          'destination' => '',
          'advanced' => array(
            'title' => '',
            'target' => '',
            'class' => '',
            'rel' => '',
            'text' => '',
          ),
        ),
      ),
    ),
  );
  $export['node|blogpost|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blogpost|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blogpost';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'blog_teaser' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:0:{}s:4:"type";s:11:"views_panes";s:7:"subtype";s:17:"blog-panel_pane_1";}',
        'load_terms' => 1,
        'ft' => array(),
        'linked_field' => array(
          'linked' => 0,
          'destination' => '',
          'advanced' => array(
            'title' => '',
            'target' => '',
            'class' => '',
            'rel' => '',
            'text' => '',
          ),
        ),
      ),
    ),
  );
  $export['node|blogpost|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function pw_blog_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'blog_petition_teaser';
  $ds_field->label = 'Blog Petition Teaser';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['blog_petition_teaser'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function pw_blog_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blogpost|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blogpost';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'post_date',
        2 => 'author',
        3 => 'comments',
        4 => 'sharethis',
        5 => 'field_teaser_image',
        6 => 'body',
        7 => 'field_blogpost_blogtags',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'post_date' => 'ds_content',
      'author' => 'ds_content',
      'comments' => 'ds_content',
      'sharethis' => 'ds_content',
      'field_teaser_image' => 'ds_content',
      'body' => 'ds_content',
      'field_blogpost_blogtags' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
    'hide_sidebars' => 0,
  );
  $export['node|blogpost|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blogpost|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blogpost';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'sharethis',
        1 => 'sharebuttons',
        2 => 'custom_comment_counter',
        3 => 'title',
        4 => 'field_blogpost_blogtags',
        5 => 'group_blog_author',
        6 => 'post_date',
        7 => 'group_blog_metainformation',
        8 => 'author_linked_to_contact_form',
        9 => 'body',
        10 => 'field_blockreference',
        11 => 'field_blogpost_categories',
        12 => 'sharethis_horizontal',
        13 => 'group_blog_social_media',
        14 => 'comments',
      ),
    ),
    'fields' => array(
      'sharethis' => 'ds_content',
      'sharebuttons' => 'ds_content',
      'custom_comment_counter' => 'ds_content',
      'title' => 'ds_content',
      'field_blogpost_blogtags' => 'ds_content',
      'group_blog_author' => 'ds_content',
      'post_date' => 'ds_content',
      'group_blog_metainformation' => 'ds_content',
      'author_linked_to_contact_form' => 'ds_content',
      'body' => 'ds_content',
      'field_blockreference' => 'ds_content',
      'field_blogpost_categories' => 'ds_content',
      'sharethis_horizontal' => 'ds_content',
      'group_blog_social_media' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '1',
    'page_option_title' => '',
    'hide_sidebars' => 0,
  );
  $export['node|blogpost|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blogpost|rss';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blogpost';
  $ds_layout->view_mode = 'rss';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|blogpost|rss'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blogpost|search_result';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blogpost';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'post_date',
        1 => 'group_grid_6',
        2 => 'title',
        3 => 'search_snippet',
        4 => 'node_link',
      ),
    ),
    'fields' => array(
      'post_date' => 'ds_content',
      'group_grid_6' => 'ds_content',
      'title' => 'ds_content',
      'search_snippet' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
    'hide_sidebars' => 0,
  );
  $export['node|blogpost|search_result'] = $ds_layout;

  return $export;
}
