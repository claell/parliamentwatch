<?php
/**
 * @file
 * pw_blog.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function pw_blog_field_default_fields() {
  $fields = array();

  // Exported field: 'comment-comment_node_blogpost-comment_body'.
  $fields['comment-comment_node_blogpost-comment_body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'comment',
      ),
      'field_name' => 'comment_body',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'comment_node_blogpost',
      'default_value' => array(
        0 => array(
          'value' => '',
          'format' => 'plain_text',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'comment',
      'field_name' => 'comment_body',
      'label' => 'Kommentar',
      'required' => 1,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'copyright' => 0,
            'filtered_html' => 0,
            'full_html' => 0,
            'html_mail' => 0,
            'managed_content' => 0,
            'php_code' => 0,
            'plain_text' => 'plain_text',
          ),
          'allowed_formats_toggle' => 1,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'copyright' => array(
                'weight' => '0',
              ),
              'filtered_html' => array(
                'weight' => '-9',
              ),
              'full_html' => array(
                'weight' => '-8',
              ),
              'html_mail' => array(
                'weight' => '0',
              ),
              'managed_content' => array(
                'weight' => '-10',
              ),
              'php_code' => array(
                'weight' => '-6',
              ),
              'plain_text' => array(
                'weight' => '-7',
              ),
            ),
          ),
        ),
        'exclude_cv' => FALSE,
        'linkit' => array(
          'enable' => 0,
          'insert_plugin' => '',
        ),
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => '',
          'maxlength_js_enforce' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'maxlength_js_truncate_html' => 0,
          'rows' => '10',
        ),
        'type' => 'text_textarea',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'node-blogpost-body'.
  $fields['node-blogpost-body'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '1',
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'blogpost',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '6',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '5',
        ),
        'print' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '5',
        ),
        'pw_newsletter' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'trim_length' => '600',
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => '2',
        ),
        'rss' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => '0',
        ),
        'search_index' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => '6',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '30',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => '3',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => 1,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'ds_code' => 0,
            'filtered_html' => 'filtered_html',
            'full_html' => 'full_html',
            'managed_content' => 'managed_content',
            'php_code' => 0,
            'plain_text' => 0,
          ),
          'allowed_formats_toggle' => 1,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'ds_code' => array(
                'weight' => '-5',
              ),
              'filtered_html' => array(
                'weight' => '-9',
              ),
              'full_html' => array(
                'weight' => '-8',
              ),
              'managed_content' => array(
                'weight' => '-10',
              ),
              'php_code' => array(
                'weight' => '-6',
              ),
              'plain_text' => array(
                'weight' => '-7',
              ),
            ),
          ),
        ),
        'display_summary' => 1,
        'exclude_cv' => FALSE,
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '20',
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'node-blogpost-field_blockreference'.
  $fields['node-blogpost-field_blockreference'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_blockreference',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'moddelta' => array(
          0 => 'moddelta',
        ),
      ),
      'locked' => '0',
      'module' => 'blockreference',
      'settings' => array(
        'referenceable_modules' => array(),
      ),
      'translatable' => '0',
      'type' => 'blockreference',
    ),
    'field_instance' => array(
      'bundle' => 'blogpost',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Der gewählte Block wird automatisch zwischen dem Text und den Kommentaren ausgegeben.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '8',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'blockreference',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'blockreference_without_title',
          'weight' => '6',
        ),
        'pw_newsletter' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '32',
        ),
        'rss' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'exclude_cv' => 0,
      'field_name' => 'field_blockreference',
      'label' => 'Block Referenz',
      'required' => 0,
      'settings' => array(
        'blockreference_modules' => array(
          'antispam' => 0,
          'apachesolr_search' => 0,
          'block' => 'block',
          'comment' => 0,
          'context_ui' => 0,
          'custom_search_blocks' => 0,
          'delta_blocks' => 0,
          'devel' => 0,
          'diff' => 0,
          'ds_extras' => 0,
          'facetapi' => 0,
          'featured_content' => 0,
          'locale' => 0,
          'masquerade' => 0,
          'menu' => 0,
          'menu_block' => 0,
          'node' => 0,
          'piwik_reports' => 0,
          'pw_login_once' => 0,
          'pw_vote' => 0,
          'quicktabs' => 0,
          'search' => 0,
          'search_api_page' => 0,
          'sharethis' => 0,
          'submenutree' => 0,
          'system' => 0,
          'tagadelic' => 0,
          'tb_megamenu' => 0,
          'text_resize' => 0,
          'user' => 0,
          'user_diff' => 0,
          'views' => 'views',
          'webform' => 'webform',
        ),
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        ),
        'type' => 'options_select',
        'weight' => '4',
      ),
    ),
  );

  // Exported field: 'node-blogpost-field_blogpost_blogtags'.
  $fields['node-blogpost-field_blogpost_blogtags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_blogpost_blogtags',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'blogtags',
            'parent' => '0',
          ),
        ),
        'options_list_callback' => NULL,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'blogpost',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'textformatter',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'textformatter_class' => '',
            'textformatter_comma_and' => 0,
            'textformatter_comma_full_stop' => 0,
            'textformatter_comma_override' => 0,
            'textformatter_comma_tag' => '0',
            'textformatter_contrib' => array(),
            'textformatter_separator_custom' => '',
            'textformatter_separator_custom_class' => '',
            'textformatter_separator_custom_tag' => '0',
            'textformatter_term_plain' => 0,
            'textformatter_type' => 'comma',
          ),
          'type' => 'textformatter_list',
          'weight' => '7',
        ),
        'full' => array(
          'label' => 'hidden',
          'module' => 'textformatter',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'textformatter_class' => '',
            'textformatter_comma_and' => 0,
            'textformatter_comma_full_stop' => 0,
            'textformatter_comma_override' => 0,
            'textformatter_comma_tag' => '0',
            'textformatter_contrib' => array(),
            'textformatter_separator_custom' => '',
            'textformatter_separator_custom_class' => 'textformatter-separator',
            'textformatter_separator_custom_tag' => 'span',
            'textformatter_term_plain' => 0,
            'textformatter_type' => 'comma',
          ),
          'type' => 'textformatter_list',
          'weight' => '2',
        ),
        'print' => array(
          'label' => 'hidden',
          'module' => 'taxonomy',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'taxonomy_term_reference_link',
          'weight' => '3',
        ),
        'pw_newsletter' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '30',
        ),
        'rss' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '17',
        ),
        'search_index' => array(
          'label' => 'hidden',
          'module' => 'textformatter',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'textformatter_class' => '',
            'textformatter_comma_and' => 0,
            'textformatter_comma_full_stop' => 0,
            'textformatter_comma_override' => 0,
            'textformatter_comma_tag' => '0',
            'textformatter_contrib' => array(),
            'textformatter_separator_custom' => '',
            'textformatter_separator_custom_class' => '',
            'textformatter_separator_custom_tag' => '0',
            'textformatter_term_plain' => 0,
            'textformatter_type' => 'comma',
          ),
          'type' => 'textformatter_list',
          'weight' => '7',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '32',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'ds',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'taxonomy_term_link' => 1,
            'taxonomy_term_separator' => ', ',
          ),
          'type' => 'ds_taxonomy_separator',
          'weight' => '4',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'field_name' => 'field_blogpost_blogtags',
      'label' => 'Tags',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => '5',
      ),
    ),
  );

  // Exported field: 'node-blogpost-field_blogpost_categories'.
  $fields['node-blogpost-field_blogpost_categories'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_blogpost_categories',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'blogcategories',
            'parent' => '0',
          ),
        ),
        'options_list_callback' => NULL,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'blogpost',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '1',
        ),
        'full' => array(
          'label' => 'inline',
          'module' => 'textformatter',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'textformatter_class' => '',
            'textformatter_comma_and' => 0,
            'textformatter_comma_full_stop' => 0,
            'textformatter_comma_override' => 0,
            'textformatter_comma_tag' => '0',
            'textformatter_contrib' => array(),
            'textformatter_separator_custom' => '',
            'textformatter_separator_custom_class' => 'textformatter-separator',
            'textformatter_separator_custom_tag' => 'span',
            'textformatter_term_plain' => 0,
            'textformatter_type' => 'comma',
          ),
          'type' => 'textformatter_list',
          'weight' => '6',
        ),
        'pw_newsletter' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '31',
        ),
        'rss' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '19',
        ),
        'search_result' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '34',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'ds',
          'settings' => array(
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
            'taxonomy_term_link' => TRUE,
            'taxonomy_term_separator' => ', ',
          ),
          'type' => 'ds_taxonomy_separator',
          'weight' => '2',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'field_name' => 'field_blogpost_categories',
      'label' => 'Categories',
      'required' => 0,
      'settings' => array(
        'exclude_cv' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'options',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'options_buttons',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'node-blogpost-field_teaser_image'.
  $fields['node-blogpost-field_teaser_image'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_teaser_image',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'blogpost',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'colorbox' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'file_entity',
          'settings' => array(
            'file_view_mode' => 'pw_file_landscape_l',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'file_rendered',
          'weight' => '5',
        ),
        'full' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '32',
        ),
        'pw_newsletter' => array(
          'label' => 'hidden',
          'module' => 'file_entity',
          'settings' => array(
            'file_view_mode' => 'pw_file_landscape_l',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'file_rendered',
          'weight' => '1',
        ),
        'rss' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '18',
        ),
        'search_index' => array(
          'label' => 'hidden',
          'module' => 'file_entity',
          'settings' => array(
            'file_view_mode' => 'pw_file_landscape_l',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'file_rendered',
          'weight' => '5',
        ),
        'search_result' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '33',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => 'content',
            'image_style' => 'pw_landscape_l',
            'linked_field' => array(
              'advanced' => array(
                'class' => '',
                'rel' => '',
                'target' => '',
                'text' => '',
                'title' => '',
              ),
              'destination' => '',
              'linked' => 0,
            ),
          ),
          'type' => 'image',
          'weight' => '1',
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'field_name' => 'field_teaser_image',
      'label' => 'Teaser image',
      'required' => 0,
      'settings' => array(
        'alt_field' => 1,
        'default_image' => 0,
        'exclude_cv' => FALSE,
        'file_directory' => 'blog',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            0 => 'public',
            1 => 'private',
          ),
          'allowed_types' => array(
            0 => 'image',
          ),
          'browser_plugins' => array(),
          'filefield_sources' => array(
            'filefield_sources' => array(
              'attach' => 0,
              'reference' => 0,
              'remote' => 0,
            ),
            'source_attach' => array(
              'absolute' => '0',
              'attach_mode' => 'copy',
              'path' => 'file_attach',
            ),
            'source_reference' => array(
              'autocomplete' => '0',
            ),
          ),
          'preview_image_style' => 'pw_landscape_l',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'media_generic',
        'weight' => '2',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Block Referenz');
  t('Body');
  t('Categories');
  t('Der gewählte Block wird automatisch zwischen dem Text und den Kommentaren ausgegeben.');
  t('Kommentar');
  t('Tags');
  t('Teaser image');

  return $fields;
}
