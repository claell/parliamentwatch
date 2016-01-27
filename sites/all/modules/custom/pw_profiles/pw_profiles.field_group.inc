<?php
/**
 * @file
 * pw_profiles.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function pw_profiles_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basics|user|user|default';
  $field_group->group_name = 'group_basics';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics ID Wrapper',
    'weight' => '2',
    'children' => array(
      0 => 'group_user_basics',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basics ID Wrapper',
      'instance_settings' => array(
        'classes' => 'add-sharethis clear-both',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_basics|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_grid_6|user|user|search_result';
  $field_group->group_name = 'group_grid_6';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'search_result';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Grid 6 Wrapper',
    'weight' => '1',
    'children' => array(
      0 => 'field_user_answers_give',
      1 => 'field_user_fname',
      2 => 'field_user_lname',
      3 => 'field_user_questions_get',
      4 => 'field_user_parliament',
      5 => 'field_user_party',
      6 => 'field_user_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Grid 6 Wrapper',
      'instance_settings' => array(
        'classes' => 'grid-6 omega',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_grid_6|user|user|search_result'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_managed_content|user|user|form';
  $field_group->group_name = 'group_managed_content';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Managed Content',
    'weight' => '13',
    'children' => array(
      0 => 'field_user_gender',
      1 => 'field_user_question_form_closed',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_managed_content|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_polls|user|user|default';
  $field_group->group_name = 'group_polls';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Polls ID Wrapper',
    'weight' => '4',
    'children' => array(
      0 => 'group_user_polls',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Polls ID Wrapper',
      'instance_settings' => array(
        'classes' => 'add-sharethis clear-both',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_polls|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_premium|user|user|form';
  $field_group->group_name = 'group_premium';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Premium',
    'weight' => '11',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_premium|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profiles_mouseover|user|user|pw_profiles_list_compact';
  $field_group->group_name = 'group_profiles_mouseover';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'pw_profiles_list_compact';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Mouseover',
    'weight' => '7',
    'children' => array(
      0 => 'field_user_commitee',
      1 => 'field_user_constituency',
      2 => 'field_user_parliament',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Mouseover',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_profiles_mouseover|user|user|pw_profiles_list_compact'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_roles|user|user|default';
  $field_group->group_name = 'group_roles';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Roles ID Wrapper',
    'weight' => '3',
    'children' => array(
      0 => 'group_user_commitee',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Roles ID Wrapper',
      'instance_settings' => array(
        'classes' => 'add-sharethis clear-both',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_roles|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_admin|user|user|form';
  $field_group->group_name = 'group_user_admin';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Admin Settings',
    'weight' => '15',
    'children' => array(
      0 => 'field_user_first_letter_lname',
      1 => 'field_user_external_url',
      2 => 'field_user_roles_for_view_mode_s',
      3 => 'field_share_sum',
      4 => 'ckeditor',
      5 => 'piwik',
      6 => 'redirect',
      7 => 'timezone',
      8 => 'xmlsitemap',
      9 => 'locale',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Admin Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_user_admin|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_affiliation|user|user|form';
  $field_group->group_name = 'group_user_affiliation';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Political Affiliation',
    'weight' => '10',
    'children' => array(
      0 => 'field_user_commitee',
      1 => 'field_user_parliament',
      2 => 'field_user_party',
      3 => 'field_user_political_roles',
      4 => 'field_user_valid',
      5 => 'field_user_election_result',
      6 => 'field_user_constituency_won',
      7 => 'field_user_list_won',
      8 => 'field_user_fraction',
      9 => 'field_user_valid_from',
      10 => 'field_user_valid_until',
      11 => 'field_user_joined',
      12 => 'field_user_retired',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Political Affiliation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_user_affiliation|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_basics_additional|user|user|default';
  $field_group->group_name = 'group_user_basics_additional';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_user_basics';
  $field_group->data = array(
    'label' => 'Additional',
    'weight' => '15',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Additional',
      'instance_settings' => array(
        'classes' => '',
        'description' => 'Additional Links',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_basics_additional|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_basics_additional|user|user|user_deputy';
  $field_group->group_name = 'group_user_basics_additional';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'user_deputy';
  $field_group->parent_name = 'group_user_basics';
  $field_group->data = array(
    'label' => 'User Basics Additional',
    'weight' => '9',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_basics_additional|user|user|user_deputy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_basics_basics|user|user|default';
  $field_group->group_name = 'group_user_basics_basics';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_user_basics';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '13',
    'children' => array(
      0 => 'field_user_job_skills',
      1 => 'field_user_constituency',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'classes' => '',
        'description' => 'Basic information',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_basics_basics|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_basics_data|user|user|user_deputy';
  $field_group->group_name = 'group_user_basics_data';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'user_deputy';
  $field_group->parent_name = 'group_user_basics';
  $field_group->data = array(
    'label' => 'User Basics Data',
    'weight' => '8',
    'children' => array(
      0 => 'field_user_constituency',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_basics_data|user|user|user_deputy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_basics|user|user|default';
  $field_group->group_name = 'group_user_basics';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_basics';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '7',
    'children' => array(
      0 => 'group_user_basics_additional',
      1 => 'group_user_basics_basics',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_user_basics|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_basics|user|user|user_deputy';
  $field_group->group_name = 'group_user_basics';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'user_deputy';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Basics',
    'weight' => '52',
    'children' => array(
      0 => 'group_user_basics_additional',
      1 => 'group_user_basics_data',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_user_basics|user|user|user_deputy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_commitee_tab|user|user|default';
  $field_group->group_name = 'group_user_commitee_tab';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_user_commitee';
  $field_group->data = array(
    'label' => 'Political Roles',
    'weight' => '1',
    'children' => array(
      0 => 'field_user_commitee',
      1 => 'field_user_political_roles',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Political Roles',
      'instance_settings' => array(
        'classes' => '',
        'description' => 'Political Roles',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_user_commitee_tab|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_commitee|user|user|default';
  $field_group->group_name = 'group_user_commitee';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_roles';
  $field_group->data = array(
    'label' => 'Commitee Fieldgroup',
    'weight' => '8',
    'children' => array(
      0 => 'group_user_commitee_tab',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_user_commitee|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_dialogue|user|user|form';
  $field_group->group_name = 'group_user_dialogue';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dialogue Data',
    'weight' => '14',
    'children' => array(
      0 => 'field_user_answers_give',
      1 => 'field_user_questions_get',
      2 => 'field_user_qanda_ratio',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Dialogue Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_user_dialogue|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_name|user|user|default';
  $field_group->group_name = 'group_user_name';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Name',
    'weight' => '1',
    'children' => array(
      0 => 'field_user_fname',
      1 => 'field_user_lname',
      2 => 'field_user_party',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Name',
      'instance_settings' => array(
        'classes' => 'h2 push-bottom-xxs',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_name|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_name|user|user|premium_user';
  $field_group->group_name = 'group_user_name';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'premium_user';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Name',
    'weight' => '58',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_name|user|user|premium_user'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_name|user|user|user_search';
  $field_group->group_name = 'group_user_name';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'user_search';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User name',
    'weight' => '1',
    'children' => array(
      0 => 'field_user_fname',
      1 => 'field_user_lname',
      2 => 'field_user_party',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'User name',
      'instance_settings' => array(
        'classes' => 'h3',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_name|user|user|user_search'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_personal_data|user|user|form';
  $field_group->group_name = 'group_user_personal_data';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Data',
    'weight' => '9',
    'children' => array(
      0 => 'field_user_birthday',
      1 => 'field_user_childs',
      2 => 'field_user_job_skills',
      3 => 'field_user_marriage_status',
      4 => 'field_user_pseudonym',
      5 => 'field_user_address',
      6 => 'field_user_constituency',
      7 => 'field_user_education',
      8 => 'field_user_list_position',
      9 => 'field_user_age',
      10 => 'field_user_phone',
      11 => 'field_user_public_mail',
      12 => 'field_user_list',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Personal Data',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_user_personal_data|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_polls_archive|user|user|default';
  $field_group->group_name = 'group_user_polls_archive';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_user_polls';
  $field_group->data = array(
    'label' => 'Polls archive',
    'weight' => '32',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_polls_archive|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_polls_archive|user|user|user_deputy';
  $field_group->group_name = 'group_user_polls_archive';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'user_deputy';
  $field_group->parent_name = 'group_user_polls';
  $field_group->data = array(
    'label' => 'User Polls Archive',
    'weight' => '34',
    'children' => array(
      0 => 'polls_archive_view',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_polls_archive|user|user|user_deputy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_polls_current|user|user|user_deputy';
  $field_group->group_name = 'group_user_polls_current';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'user_deputy';
  $field_group->parent_name = 'group_user_polls';
  $field_group->data = array(
    'label' => 'User Polls Current',
    'weight' => '7',
    'children' => array(
      0 => 'polls_profile_last',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_polls_current|user|user|user_deputy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_polls_last|user|user|default';
  $field_group->group_name = 'group_user_polls_last';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_user_polls';
  $field_group->data = array(
    'label' => 'Last poll',
    'weight' => '31',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_polls_last|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_polls|user|user|default';
  $field_group->group_name = 'group_user_polls';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_polls';
  $field_group->data = array(
    'label' => 'Polls',
    'weight' => '1',
    'children' => array(
      0 => 'group_user_polls_archive',
      1 => 'group_user_polls_last',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_user_polls|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_polls|user|user|user_deputy';
  $field_group->group_name = 'group_user_polls';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'user_deputy';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Polls',
    'weight' => '53',
    'children' => array(
      0 => 'group_user_polls_archive',
      1 => 'group_user_polls_current',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_user_polls|user|user|user_deputy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium_about|user|user|form';
  $field_group->group_name = 'group_user_premium_about';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_premium';
  $field_group->data = array(
    'label' => 'About me',
    'weight' => '18',
    'children' => array(
      0 => 'field_user_about',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'About me',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_user_premium_about|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium_fields|user|user|form';
  $field_group->group_name = 'group_user_premium_fields';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Premium Fields',
    'weight' => '12',
    'children' => array(
      0 => 'group_user_premium',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Premium Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Profilfoto, Social-Media, Bildergalerie, Kalender, Biografie, politische Ziele',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_user_premium_fields|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium_gallery|user|user|form';
  $field_group->group_name = 'group_user_premium_gallery';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_premium';
  $field_group->data = array(
    'label' => 'Image Gallery',
    'weight' => '20',
    'children' => array(
      0 => 'field_user_image_gallery',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_user_premium_gallery|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium_goals|user|user|form';
  $field_group->group_name = 'group_user_premium_goals';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_premium';
  $field_group->data = array(
    'label' => 'Political Goals',
    'weight' => '21',
    'children' => array(
      0 => 'field_user_political_goals',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_user_premium_goals|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium_links|user|user|form';
  $field_group->group_name = 'group_user_premium_links';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_premium';
  $field_group->data = array(
    'label' => 'External Links',
    'weight' => '19',
    'children' => array(
      0 => 'field_user_links_more',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_user_premium_links|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium_picture|user|user|form';
  $field_group->group_name = 'group_user_premium_picture';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile picture',
    'weight' => '17',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_user_premium_picture|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium_twitter|user|user|form';
  $field_group->group_name = 'group_user_premium_twitter';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_premium';
  $field_group->data = array(
    'label' => 'Twitter',
    'weight' => '22',
    'children' => array(
      0 => 'field_user_twitter_account',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_user_premium_twitter|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_premium|user|user|form';
  $field_group->group_name = 'group_user_premium';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_user_premium_fields';
  $field_group->data = array(
    'label' => 'Premium fields',
    'weight' => '8',
    'children' => array(
      0 => 'group_user_premium_about',
      1 => 'group_user_premium_gallery',
      2 => 'group_user_premium_goals',
      3 => 'group_user_premium_links',
      4 => 'group_user_premium_twitter',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_user_premium|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_roles_archive|user|user|user_deputy';
  $field_group->group_name = 'group_user_roles_archive';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'user_deputy';
  $field_group->parent_name = 'group_user_roles';
  $field_group->data = array(
    'label' => 'User Roles Archive',
    'weight' => '62',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_roles_archive|user|user|user_deputy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_roles_current|user|user|user_deputy';
  $field_group->group_name = 'group_user_roles_current';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'user_deputy';
  $field_group->parent_name = 'group_user_roles';
  $field_group->data = array(
    'label' => 'User Roles Current',
    'weight' => '59',
    'children' => array(
      0 => 'field_user_commitee',
      1 => 'field_user_political_roles',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_user_roles_current|user|user|user_deputy'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_roles|user|user|user_deputy';
  $field_group->group_name = 'group_user_roles';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'user_deputy';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Roles',
    'weight' => '54',
    'children' => array(
      0 => 'group_user_roles_archive',
      1 => 'group_user_roles_current',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_user_roles|user|user|user_deputy'] = $field_group;

  return $export;
}
