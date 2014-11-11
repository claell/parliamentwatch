<?php
/**
 * @file
 * pw_profiles.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function pw_profiles_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|calendar_entry|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'calendar_entry';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'sharethis' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'back_to_calendar' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'short_profile_premium_sub' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'title' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'push-bottom-l',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_calendar_entry_address' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'p',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'strong',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_calendar_entry_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'strong',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|calendar_entry|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|search_result';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'search_result';
  $ds_fieldsetting->settings = array(
    'go_to_profile' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'name' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'span',
        'class' => 'link-profile',
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'text-right',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_user_answers_give' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_user_fname' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'strong',
          'ow-cl' => 'field-fname',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_user_lname' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'strong',
          'ow-cl' => 'field-lname',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_user_questions_get' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'field-questionsget',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_user_parliament' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'small',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_user_party' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_user_picture' => array(
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
    'field_user_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'strong',
          'ow-cl' => 'field-title',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['user|user|search_result'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|user_candidate';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'user_candidate';
  $ds_fieldsetting->settings = array(
    'pw_kandidatencheck' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 1,
        'title_wrapper' => 'h2',
        'ctools' => 'a:3:{s:4:"conf";a:0:{}s:4:"type";s:11:"views_panes";s:7:"subtype";s:36:"pw_kandidatencheck-profile_slideshow";}',
        'load_terms' => 1,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pw-expandable-mobile clear clearfix push-bottom-l',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-user-kc"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'question_and_answers_filter' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'desktop-only',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'question_form' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw_block_user_questionform"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'short_profile_deputy_main' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'push-bottom-l',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_basic_info' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pw-expandable-mobile clear clearfix push-bottom-l',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-user-basics"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_profile_api_link' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'block desktop-only',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_questions_and_answers' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 1,
        'title_wrapper' => 'h2',
        'ctools' => 'a:3:{s:4:"conf";a:4:{s:12:"link_to_view";i:0;s:9:"use_pager";i:1;s:8:"pager_id";s:1:"0";s:14:"items_per_page";s:1:"5";}s:4:"type";s:11:"views_panes";s:7:"subtype";s:33:"profile_questions_answers-profile";}',
        'load_terms' => 1,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-questions-and-answers"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_wrong_data' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'block desktop-only',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'pw_slider' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'block',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_revision_switch' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'block',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['user|user|user_candidate'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|user_deputy';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'user_deputy';
  $ds_fieldsetting->settings = array(
    'bundestagsradar' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'block',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'question_and_answers_filter' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'desktop-only',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'question_form' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw_block_user_questionform"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'short_profile_deputy_main' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'push-bottom-l',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_basic_info' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pw-expandable-mobile clear clearfix push-bottom-l',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-user-basics"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_profile_api_link' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'block desktop-only',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'user_questions_and_answers' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 1,
        'title_wrapper' => 'h2',
        'ctools' => 'a:3:{s:4:"conf";a:4:{s:12:"link_to_view";i:0;s:9:"use_pager";i:0;s:8:"pager_id";s:1:"0";s:14:"items_per_page";s:1:"0";}s:4:"type";s:11:"views_panes";s:7:"subtype";s:33:"profile_questions_answers-profile";}',
        'load_terms' => 1,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-questions-and-answers"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_wrong_data' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'block desktop-only',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'pw_slider' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'block',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_revision_switch' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'block',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['user|user|user_deputy'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|user_dialogue_search_snippet';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'user_dialogue_search_snippet';
  $ds_fieldsetting->settings = array(
    'field_user_fname' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'strong',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_user_lname' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'strong',
          'ow-cl' => 'field-lname',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_user_party' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_user_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'strong',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['user|user|user_dialogue_search_snippet'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|user_premium';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'user_premium';
  $ds_fieldsetting->settings = array(
    'pw_kandidatencheck' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 1,
        'title_wrapper' => 'h2',
        'ctools' => 'a:3:{s:4:"conf";a:0:{}s:4:"type";s:11:"views_panes";s:7:"subtype";s:36:"pw_kandidatencheck-profile_slideshow";}',
        'load_terms' => 1,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'clear clearfix push-bottom-l',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-user-kc"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'additional_links' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pw-expandable-mobile clear clearfix push-bottom-l relative',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-user-links"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'question_and_answers_filter' => array(
      'weight' => '19',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'desktop-only',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'question_form' => array(
      'weight' => '18',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw_block_user_questionform"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'short_profile' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'push-bottom-l',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_about' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pw-expandable-mobile clear clearfix push-bottom-l relative',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-user-about"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_basic_info' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pw-expandable-mobile clear clearfix push-bottom-l',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-user-basics"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_calendar' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pw-expandable-mobile clear clearfix push-bottom-l relative',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-user-calendar"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_image_gallery' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pw-expandable-mobile clear clearfix push-bottom-l relative',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-user-gallery"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_political_goals' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pw-expandable-mobile clear clearfix push-bottom-l relative',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-user-goals"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_profile_api_link' => array(
      'weight' => '16',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'block desktop-only',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'user_questions_and_answers' => array(
      'weight' => '17',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 1,
        'title_wrapper' => 'h2',
        'ctools' => 'a:3:{s:4:"conf";a:4:{s:12:"link_to_view";i:0;s:9:"use_pager";i:0;s:8:"pager_id";s:1:"0";s:14:"items_per_page";s:1:"0";}s:4:"type";s:11:"views_panes";s:7:"subtype";s:33:"profile_questions_answers-profile";}',
        'load_terms' => 1,
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => '',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-questions-and-answers"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_tweets' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'pw-expandable-mobile clear clearfix push-bottom-l relative',
          'ow-def-cl' => FALSE,
          'ow-at' => 'id="pw-block-user-twitter"',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_wrong_data' => array(
      'weight' => '15',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'block desktop-only',
          'ow-def-cl' => TRUE,
          'ow-at' => '',
          'ow-def-at' => TRUE,
        ),
      ),
    ),
    'pw_slider' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'block',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'user_revision_switch' => array(
      'weight' => '14',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'block',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['user|user|user_premium'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|user_search';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'user_search';
  $ds_fieldsetting->settings = array(
    'name' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'div',
        'class' => 'float-right link-profile',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_user_fname' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_user_lname' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_user_party' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_user_picture' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'float-left',
        ),
      ),
    ),
    'group_user_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'h3',
        ),
      ),
    ),
  );
  $export['user|user|user_search'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function pw_profiles_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'additional_links';
  $ds_field->label = 'User Additional Links ';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|1269dd557bad56827781d3d678e62ebf',
    'block_render' => '2',
  );
  $export['additional_links'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'back_to_calendar';
  $ds_field->label = 'Back to Calendar';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|calendar-block_4',
    'block_render' => '1',
  );
  $export['back_to_calendar'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'bundestagsradar';
  $ds_field->label = 'Bundestagsradar';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$uid = arg(1);
$user_fields = user_load($uid);
$field_user_parliament = $user_fields->field_user_parliament[\'und\'][0][\'tid\'];
if($field_user_parliament == 6501){
    $block = block_load(\'block\', \'23\');
    print drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
}
?>',
      'format' => 'php_code',
    ),
    'use_token' => 0,
  );
  $export['bundestagsradar'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'go_to_profile';
  $ds_field->label = 'Go to profile';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'user' => 'user',
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
  $export['go_to_profile'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'polls_archive_view';
  $ds_field->label = 'Polls archive view';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|polls_profile-block',
    'block_render' => '1',
  );
  $export['polls_archive_view'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'polls_profile_last';
  $ds_field->label = 'Polls profile last';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|polls_profile-last',
    'block_render' => '1',
  );
  $export['polls_profile_last'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'question_and_answers_filter';
  $ds_field->label = 'Question and Answers Filter';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|1aaf3482d7a482c92318ccf7dc354a3c',
    'block_render' => '2',
  );
  $export['question_and_answers_filter'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'question_and_answers_switcher';
  $ds_field->label = 'Question and Answers Switcher';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<form action="" id="form-view-mode-switcher" method="post" name="view-mode-switcher" class="views-exposed-form">
	<div class="description"><div class="ic-info"><div class="info-title"></div><div class="info-content element-hidden"><?php print t(\'Bei "normaler Ansicht" erhalten Sie die Fragen und Antworten in voller Länge. Um sich schnell einen Überblick zu verschaffen, wählen Sie "verschlagwortete Ansicht". Dann wird Ihnen ein redaktionell ausgewählter Ausschnitt aus den Fragen und Antworten angezeigt.\'); ?></div></div></div>
       <fieldset class="views-exposed-widget">
                <label><?php print t(\'Change view\'); ?></label>
                <div class="form-radios">
		    <div class="form-item"><input class="view-mode-full form-radio" name="group1" id="group1_1" type="radio" value="full" checked="checked" /><label for="group1_1" class="option"><?php print t(\'Full View\'); ?></label></div>
		    <div class="form-item"><input class="view-mode-teaser form-radio" name="group1" id="group1_2" type="radio" value="teaser" /><label for="group1_2" class="option"><?php print t(\'Teaser View\'); ?></label></div>
              </div>
	</fieldset>
</form>',
      'format' => 'php_code',
    ),
    'use_token' => 0,
  );
  $export['question_and_answers_switcher'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'question_form';
  $ds_field->label = 'Question form';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'webform|client-block-10446',
    'block_render' => '3',
  );
  $export['question_form'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'question_form_anonymous';
  $ds_field->label = 'Question form anonymous';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'webform|client-block-796',
    'block_render' => '2',
  );
  $export['question_form_anonymous'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'same_constituency';
  $ds_field->label = 'Same Constituency';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|9a5bb2cea55a5e3aeadcdd18ecf4d2e6',
    'block_render' => '2',
  );
  $export['same_constituency'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'sharethis_polls_profile';
  $ds_field->label = 'ShareThis polls profile';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|polls_profile-block_2',
    'block_render' => '3',
  );
  $export['sharethis_polls_profile'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'short_profile';
  $ds_field->label = 'Short Profile Premium Main';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|1bfdad95b3077966cebee9136e4f94e5',
    'block_render' => '3',
  );
  $export['short_profile'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'short_profile_deputy_main';
  $ds_field->label = 'Short Profile Deputy Main';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|f4f58a460e337dd20c6b7fbc8a2f0b6d',
    'block_render' => '3',
  );
  $export['short_profile_deputy_main'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'short_profile_deputy_sub';
  $ds_field->label = 'Short Profile Deputy Sub';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|f9bd2917711d3878f5b8f68f3af9161f',
    'block_render' => '3',
  );
  $export['short_profile_deputy_sub'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'short_profile_premium_sub';
  $ds_field->label = 'Short Profile Premium Sub';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|5be01ac1d52a5a6850ab10de6bf774c1',
    'block_render' => '3',
  );
  $export['short_profile_premium_sub'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_about';
  $ds_field->label = 'User About';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|4dcafc132e57885543e30b58a6f03db6',
    'block_render' => '2',
  );
  $export['user_about'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_basic_info';
  $ds_field->label = 'User Basic Info';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|901096594d39ea14f78dc9e2fefbe5e0',
    'block_render' => '2',
  );
  $export['user_basic_info'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_calendar';
  $ds_field->label = 'User Calendar';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|calendar-profile_block',
    'block_render' => '2',
  );
  $export['user_calendar'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_image_gallery';
  $ds_field->label = 'User Image Gallery';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|911001090b6fd83967d2564c46e72c20',
    'block_render' => '2',
  );
  $export['user_image_gallery'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_political_goals';
  $ds_field->label = 'User Political Goals';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|5c321d1fa4154d361026bc60361258b8',
    'block_render' => '2',
  );
  $export['user_political_goals'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_profile_api_link';
  $ds_field->label = 'User Profile API Link';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|pw_user_blocks-api_profile',
    'block_render' => '2',
  );
  $export['user_profile_api_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_questions_and_answers';
  $ds_field->label = 'Questions and Answers Profile';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'user' => 'user',
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
  $export['user_questions_and_answers'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_tweets';
  $ds_field->label = 'User Tweets';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|user_tweets-block_1',
    'block_render' => '2',
  );
  $export['user_tweets'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_wrong_data';
  $ds_field->label = 'User Wrong Data';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|pw_user_blocks-user_wrong_data',
    'block_render' => '2',
  );
  $export['user_wrong_data'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function pw_profiles_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|calendar_entry|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'calendar_entry';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'sharethis',
        1 => 'short_profile_premium_sub',
        2 => 'title',
        3 => 'field_calendar_entry_date',
        4 => 'field_calendar_entry_address',
        5 => 'body',
        6 => 'back_to_calendar',
      ),
    ),
    'fields' => array(
      'sharethis' => 'ds_content',
      'short_profile_premium_sub' => 'ds_content',
      'title' => 'ds_content',
      'field_calendar_entry_date' => 'ds_content',
      'field_calendar_entry_address' => 'ds_content',
      'body' => 'ds_content',
      'back_to_calendar' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'hide_page_title' => '0',
    'page_option_title' => '',
    'hide_sidebars' => 0,
  );
  $export['node|calendar_entry|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|search_result';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'search_result';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_user_picture',
        1 => 'go_to_profile',
        2 => 'group_grid_6',
        3 => 'name',
        4 => 'field_user_title',
        5 => 'field_user_fname',
        6 => 'field_user_lname',
        7 => 'field_user_party',
        8 => 'field_user_parliament',
        9 => 'field_user_questions_get',
        10 => 'field_user_answers_give',
      ),
    ),
    'fields' => array(
      'field_user_picture' => 'ds_content',
      'go_to_profile' => 'ds_content',
      'group_grid_6' => 'ds_content',
      'name' => 'ds_content',
      'field_user_title' => 'ds_content',
      'field_user_fname' => 'ds_content',
      'field_user_lname' => 'ds_content',
      'field_user_party' => 'ds_content',
      'field_user_parliament' => 'ds_content',
      'field_user_questions_get' => 'ds_content',
      'field_user_answers_give' => 'ds_content',
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
    'hide_sidebars' => 0,
  );
  $export['user|user|search_result'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|user_candidate';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'user_candidate';
  $ds_layout->layout = 'pw_with_sidebar_2rows_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_1' => array(
        0 => 'short_profile_deputy_main',
        1 => 'user_basic_info',
        2 => 'pw_kandidatencheck',
      ),
      'right_1' => array(
        3 => 'pw_slider',
        4 => 'user_revision_switch',
        5 => 'user_wrong_data',
        6 => 'user_profile_api_link',
      ),
      'left_2' => array(
        7 => 'user_questions_and_answers',
        8 => 'question_form',
      ),
      'right_2' => array(
        9 => 'question_and_answers_filter',
      ),
      'ds_hidden' => array(
        10 => 'field_user_party',
      ),
    ),
    'fields' => array(
      'short_profile_deputy_main' => 'left_1',
      'user_basic_info' => 'left_1',
      'pw_kandidatencheck' => 'left_1',
      'pw_slider' => 'right_1',
      'user_revision_switch' => 'right_1',
      'user_wrong_data' => 'right_1',
      'user_profile_api_link' => 'right_1',
      'user_questions_and_answers' => 'left_2',
      'question_form' => 'left_2',
      'question_and_answers_filter' => 'right_2',
      'field_user_party' => 'ds_hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left_1' => 'div',
      'right_1' => 'aside',
      'inbetween' => 'div',
      'left_2' => 'div',
      'right_2' => 'aside',
      'footer' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_sidebars' => 1,
  );
  $export['user|user|user_candidate'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|user_deputy';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'user_deputy';
  $ds_layout->layout = 'pw_with_sidebar_2rows_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_1' => array(
        0 => 'short_profile_deputy_main',
        1 => 'user_basic_info',
      ),
      'right_1' => array(
        2 => 'pw_slider',
        3 => 'user_revision_switch',
        4 => 'user_wrong_data',
        5 => 'user_profile_api_link',
        6 => 'bundestagsradar',
      ),
      'left_2' => array(
        7 => 'user_questions_and_answers',
        8 => 'question_form',
      ),
      'right_2' => array(
        9 => 'question_and_answers_filter',
      ),
      'ds_hidden' => array(
        10 => 'field_user_fname',
        11 => 'field_user_lname',
        12 => 'field_user_party',
      ),
    ),
    'fields' => array(
      'short_profile_deputy_main' => 'left_1',
      'user_basic_info' => 'left_1',
      'pw_slider' => 'right_1',
      'user_revision_switch' => 'right_1',
      'user_wrong_data' => 'right_1',
      'user_profile_api_link' => 'right_1',
      'bundestagsradar' => 'right_1',
      'user_questions_and_answers' => 'left_2',
      'question_form' => 'left_2',
      'question_and_answers_filter' => 'right_2',
      'field_user_fname' => 'ds_hidden',
      'field_user_lname' => 'ds_hidden',
      'field_user_party' => 'ds_hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left_1' => 'div',
      'right_1' => 'div',
      'inbetween' => 'div',
      'left_2' => 'div',
      'right_2' => 'div',
      'footer' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_sidebars' => 1,
  );
  $export['user|user|user_deputy'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|user_dialogue_search_snippet';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'user_dialogue_search_snippet';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_user_title',
        1 => 'field_user_fname',
        2 => 'field_user_lname',
        3 => 'field_user_party',
      ),
    ),
    'fields' => array(
      'field_user_title' => 'ds_content',
      'field_user_fname' => 'ds_content',
      'field_user_lname' => 'ds_content',
      'field_user_party' => 'ds_content',
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
    'hide_sidebars' => 0,
  );
  $export['user|user|user_dialogue_search_snippet'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|user_premium';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'user_premium';
  $ds_layout->layout = 'pw_with_sidebar_2rows_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left_1' => array(
        0 => 'short_profile',
        1 => 'user_basic_info',
        2 => 'user_about',
        3 => 'user_image_gallery',
        4 => 'user_political_goals',
        5 => 'user_tweets',
        6 => 'additional_links',
        7 => 'user_calendar',
        8 => 'pw_kandidatencheck',
      ),
      'right_1' => array(
        9 => 'pw_slider',
        10 => 'user_revision_switch',
        11 => 'user_wrong_data',
        12 => 'user_profile_api_link',
      ),
      'left_2' => array(
        13 => 'user_questions_and_answers',
        14 => 'question_form',
      ),
      'right_2' => array(
        15 => 'question_and_answers_filter',
      ),
      'ds_hidden' => array(
        16 => 'field_user_party',
      ),
    ),
    'fields' => array(
      'short_profile' => 'left_1',
      'user_basic_info' => 'left_1',
      'user_about' => 'left_1',
      'user_image_gallery' => 'left_1',
      'user_political_goals' => 'left_1',
      'user_tweets' => 'left_1',
      'additional_links' => 'left_1',
      'user_calendar' => 'left_1',
      'pw_kandidatencheck' => 'left_1',
      'pw_slider' => 'right_1',
      'user_revision_switch' => 'right_1',
      'user_wrong_data' => 'right_1',
      'user_profile_api_link' => 'right_1',
      'user_questions_and_answers' => 'left_2',
      'question_form' => 'left_2',
      'question_and_answers_filter' => 'right_2',
      'field_user_party' => 'ds_hidden',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left_1' => 'div',
      'right_1' => 'aside',
      'inbetween' => 'div',
      'left_2' => 'div',
      'right_2' => 'aside',
      'footer' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_sidebars' => 1,
  );
  $export['user|user|user_premium'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|user_search';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'user_search';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_user_picture',
        1 => 'group_user_name',
        2 => 'field_user_fname',
        3 => 'name',
        4 => 'field_user_lname',
        5 => 'field_user_party',
      ),
    ),
    'fields' => array(
      'field_user_picture' => 'ds_content',
      'group_user_name' => 'ds_content',
      'field_user_fname' => 'ds_content',
      'name' => 'ds_content',
      'field_user_lname' => 'ds_content',
      'field_user_party' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['user|user|user_search'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function pw_profiles_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'pw_file_landscape_l';
  $ds_view_mode->label = 'pw_file_landscape_l';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['pw_file_landscape_l'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'pw_file_portrait_l';
  $ds_view_mode->label = 'pw_file_portrait_l';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['pw_file_portrait_l'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'pw_file_portrait_m';
  $ds_view_mode->label = 'pw_file_portrait_m';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['pw_file_portrait_m'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'pw_file_portrait_s';
  $ds_view_mode->label = 'pw_file_portrait_s';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['pw_file_portrait_s'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'user_candidate';
  $ds_view_mode->label = 'User Candidate';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['user_candidate'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'user_deputy';
  $ds_view_mode->label = 'User Deputy';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['user_deputy'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'user_premium';
  $ds_view_mode->label = 'User Candidate Premium';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['user_premium'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'user_search';
  $ds_view_mode->label = 'User search';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['user_search'] = $ds_view_mode;

  return $export;
}
