<?php
/**
 * @file
 * pw_dialogues.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_dialogues_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'profile_questions_answers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW Dialogues';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Questions & Answers';
  $handler->display->display_options['css_class'] = 'pager-load-more';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'weiterlesen';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'first';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'zurück';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'last';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'push-bottom-l relative';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Kopfbereich: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<?php
drupal_add_js("/sites/all/themes/custom/parliamentwatch/js/shortlink.js");
?>
';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="pw-messages warning">
Mit Ihrer Auswahl wurden leider keine Ergebnisse gefunden.<br/>Bitte treffen Sie eine neue Auswahl über einen der angebotenen Filter.
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Beziehung: Kommentar: Kommentare des Beitrags */
  $handler->display->display_options['relationships']['cid']['id'] = 'cid';
  $handler->display->display_options['relationships']['cid']['table'] = 'node';
  $handler->display->display_options['relationships']['cid']['field'] = 'cid';
  /* Beziehung: Inhalt: Autor */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid_1']['label'] = 'content author';
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['id'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['table'] = 'field_data_field_dialogue_recipient';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['field'] = 'field_dialogue_recipient_target_id';
  /* Beziehung: Dateiverwendung: Datei */
  $handler->display->display_options['relationships']['user_to_file']['id'] = 'user_to_file';
  $handler->display->display_options['relationships']['user_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['user_to_file']['field'] = 'user_to_file';
  $handler->display->display_options['relationships']['user_to_file']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['relationships']['user_to_file']['label'] = 'Profilfoto';
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname']['element_default_classes'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  /* Feld: Inhalt: ShareThis Link */
  $handler->display->display_options['fields']['sharethis']['id'] = 'sharethis';
  $handler->display->display_options['fields']['sharethis']['table'] = 'node';
  $handler->display->display_options['fields']['sharethis']['field'] = 'sharethis';
  $handler->display->display_options['fields']['sharethis']['label'] = '';
  $handler->display->display_options['fields']['sharethis']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sharethis']['element_default_classes'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['label'] = 'Fieldset Question';
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
    0 => 'field_dialogue_topic',
    1 => 'created',
    2 => 'field_dialogue_sender_name',
    3 => 'field_dialogue_before_election',
    4 => 'php_3',
    5 => 'body',
    6 => 'field_dialogue_annotation_1',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['classes'] = 'question';
  /* Feld: Feld: Topic */
  $handler->display->display_options['fields']['field_dialogue_topic']['id'] = 'field_dialogue_topic';
  $handler->display->display_options['fields']['field_dialogue_topic']['table'] = 'field_data_field_dialogue_topic';
  $handler->display->display_options['fields']['field_dialogue_topic']['field'] = 'field_dialogue_topic';
  $handler->display->display_options['fields']['field_dialogue_topic']['label'] = 'Thema';
  $handler->display->display_options['fields']['field_dialogue_topic']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_dialogue_topic']['element_wrapper_class'] = 'topic float-right';
  $handler->display->display_options['fields']['field_dialogue_topic']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_topic']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_dialogue_topic']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'date_only_short';
  /* Feld: Inhalt: Sender Name */
  $handler->display->display_options['fields']['field_dialogue_sender_name']['id'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['table'] = 'field_data_field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['field'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['label'] = 'Frage von';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dialogue_sender_name']['alter']['text'] = ' [field_dialogue_sender_name]<br/><span class="subline">[created]</span>
';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_sender_name']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['element_wrapper_class'] = 'bubble';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_sender_name']['empty'] = 'anonymous<br/><span class="subline">[created]</span>';
  /* Feld: Excluded | Before Election */
  $handler->display->display_options['fields']['field_dialogue_before_election']['id'] = 'field_dialogue_before_election';
  $handler->display->display_options['fields']['field_dialogue_before_election']['table'] = 'field_data_field_dialogue_before_election';
  $handler->display->display_options['fields']['field_dialogue_before_election']['field'] = 'field_dialogue_before_election';
  $handler->display->display_options['fields']['field_dialogue_before_election']['ui_name'] = 'Excluded | Before Election';
  $handler->display->display_options['fields']['field_dialogue_before_election']['label'] = '';
  $handler->display->display_options['fields']['field_dialogue_before_election']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_dialogue_before_election']['element_label_colon'] = FALSE;
  /* Feld: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = '';
  $handler->display->display_options['fields']['php_3']['element_type'] = 'div';
  $handler->display->display_options['fields']['php_3']['element_class'] = 'dialogue-election push-bottom-s';
  $handler->display->display_options['fields']['php_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_3']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
$parliament = _pw_get_current_parliament_term();
if($data->field_field_dialogue_before_election[0][\'raw\'][\'value\'] == 1 && $parliament->field_parliament_election[\'und\'][0][\'value\'] < date(\'Y-m-d\')){
  print t(\'This was a question during election campaign.\');
}
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_class'] = 'content push-bottom-s';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Feld: Feld: Annotation */
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['id'] = 'field_dialogue_annotation_1';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['table'] = 'field_data_field_dialogue_annotation';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['field'] = 'field_dialogue_annotation';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['label'] = 'Anmerkung der Redaktion';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['element_label_class'] = 'small';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['element_wrapper_class'] = 'small annotation push-bottom-m clear';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['element_default_classes'] = FALSE;
  /* Feld: Global: Ansicht */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'profile_questions_answers';
  $handler->display->display_options['fields']['view']['display'] = 'panel_pane_1';
  $handler->display->display_options['fields']['view']['arguments'] = '[!nid]';
  /* Feld: excluded | edit question */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['ui_name'] = 'excluded | edit question';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit question';
  /* Feld: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_comment' => 'edit_comment',
    'edit_node' => 'edit_node',
    'uid' => 0,
    'nid' => 0,
    'sharethis' => 0,
    'fieldset_1' => 0,
    'field_dialogue_topic' => 0,
    'created' => 0,
    'field_dialogue_sender_name' => 0,
    'body' => 0,
    'field_dialogue_tags' => 0,
    'fieldset_2' => 0,
    'fieldset_3' => 0,
    'fieldset_5' => 0,
    'field_user_picture' => 0,
    'field_image_copyright' => 0,
    'field_user_fname' => 0,
    'field_user_lname' => 0,
    'created_1' => 0,
    'comment_body' => 0,
    'fieldset' => 0,
    'field_dialogue_topic_1' => 0,
    'path_1' => 0,
    'fieldset_4' => 0,
    'nothing_1' => 0,
    'path' => 0,
    'php' => 0,
    'php_2' => 0,
  );
  /* Sortierkriterien: Inhalt: Datum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Kontextfilter: Inhalt: Beitrags-ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'dialogue' => 'dialogue',
  );
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dialogue' => 'dialogue',
  );

  /* Display: Profile */
  $handler = $view->new_display('panel_pane', 'Profile', 'profile');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Fragen an [field_user_fname] [field_user_lname]';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['display_description'] = 'A content pane used on the profile pages';
  $handler->display->display_options['defaults']['hide_attachment_summary'] = FALSE;
  $handler->display->display_options['hide_attachment_summary'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Älteste zuerst';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Neueste zuerst';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
      ),
    ),
    'combine' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '<div class="ic-info"><div class="info-title"></div><div class="info-content element-hidden">Durchsuchen Sie die Fragen und Antworten in diesem Profil nach einem bestimmten Schlagwort</div></div>',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_dialogue_topic_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '<div class="ic-info"><div class="info-title"></div><div class="info-content element-hidden">Filtern Sie die Fragen und Antworten in diesem Profil nach einem bestimmten Thema</div></div>',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'comment_count' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '',
        'bef_slider_max' => '',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '<div class="ic-info"><div class="info-title"></div><div class="info-content element-hidden">Als \'unbeantwortet\' gelten auch Fragen, auf die Politikerinnen und Politiker mit standardisierten Textbausteinen reagieren</div></div>',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'managed_content';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'first';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'zurück';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'last';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<?php
drupal_add_js(drupal_get_path(\'theme\',\'parliamentwatch\').\'/js/shortlink.js\');
//drupal_add_js(drupal_get_path(\'theme\',\'parliamentwatch\').\'/js/hidefilter.js\');
?>
';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sortierkriterien: Inhalt: Datum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date Question';
  /* Sortierkriterien: Inhalt: Datum */
  $handler->display->display_options['sorts']['created_1']['id'] = 'created_1';
  $handler->display->display_options['sorts']['created_1']['table'] = 'node';
  $handler->display->display_options['sorts']['created_1']['field'] = 'created';
  $handler->display->display_options['sorts']['created_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created_1']['expose']['label'] = 'Datum der Frage';
  /* Sortierkriterien: Kommentar: Datum */
  $handler->display->display_options['sorts']['created_2']['id'] = 'created_2';
  $handler->display->display_options['sorts']['created_2']['table'] = 'comment';
  $handler->display->display_options['sorts']['created_2']['field'] = 'created';
  $handler->display->display_options['sorts']['created_2']['relationship'] = 'cid';
  $handler->display->display_options['sorts']['created_2']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created_2']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created_2']['expose']['label'] = 'Datum der Antwort';
  /* Sortierkriterien: Inhalt: Anzahl an Kommentaren */
  $handler->display->display_options['sorts']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['sorts']['comment_count']['order'] = 'DESC';
  $handler->display->display_options['sorts']['comment_count']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['comment_count']['expose']['label'] = 'Anzahl der Antworten';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Feld: Recipient (field_dialogue_recipient) */
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['id'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['table'] = 'field_data_field_dialogue_recipient';
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['field'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['field_dialogue_recipient_target_id']['validate_options']['type'] = 'either';
  /* Kontextfilter: Inhalt: Besitzt eine Taxonomiebegriff-TID. */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['code'] = '$cpath = explode(\'/\',current_path());
$path_uid = $cpath[1];

//if revision id is in url get parliament name form user_archive_cache table
//else return parliament id from current profile

if (array_key_exists(3, $cpath)) {
  $path_vid  =  $cpath[3];
  $term_name = db_query("SELECT parliament_name FROM {user_archive_cache} p WHERE vid = (:vids)", array(\':vids\' => $path_vid))->fetchField();
  $terms = taxonomy_get_term_by_name($term_name,\'parliaments\');
  $first_term = array_shift($terms);
  return $first_term->tid;
}
else {
  $user_fields = user_load($path_uid);
  $parliament_tid = $user_fields->field_user_parliament[\'und\'][\'0\'][\'tid\'];
  return $parliament_tid;
}';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  $handler->display->display_options['arguments']['tid']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Inhalt: Body (body) */
  $handler->display->display_options['filters']['body_value']['id'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['table'] = 'field_data_body';
  $handler->display->display_options['filters']['body_value']['field'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['body_value']['group'] = 1;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dialogue' => 'dialogue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Global: Feld-Filter kombinieren */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Frage oder Antwort nach Stichwort anzeigen';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'body' => 'body',
    'comment_body' => 'comment_body',
  );
  /* Filterkriterium: Feld: Topic (field_dialogue_topic) */
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['id'] = 'field_dialogue_topic_tid';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['table'] = 'field_data_field_dialogue_topic';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['field'] = 'field_dialogue_topic_tid';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['expose']['operator_id'] = 'field_dialogue_topic_tid_op';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['expose']['label'] = 'Nach Thema der Frage filtern';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['expose']['operator'] = 'field_dialogue_topic_tid_op';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['expose']['identifier'] = 'field_dialogue_topic_tid';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_dialogue_topic_tid']['vocabulary'] = 'dialogue_topics';
  /* Filterkriterium: Inhalt: Anzahl an Kommentaren */
  $handler->display->display_options['filters']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['filters']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['filters']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['filters']['comment_count']['operator'] = 'not empty';
  $handler->display->display_options['filters']['comment_count']['group'] = 1;
  $handler->display->display_options['filters']['comment_count']['exposed'] = TRUE;
  $handler->display->display_options['filters']['comment_count']['expose']['operator_id'] = 'comment_count_op';
  $handler->display->display_options['filters']['comment_count']['expose']['label'] = 'Anzahl an Kommentaren';
  $handler->display->display_options['filters']['comment_count']['expose']['operator'] = 'comment_count_op';
  $handler->display->display_options['filters']['comment_count']['expose']['identifier'] = 'comment_count';
  $handler->display->display_options['filters']['comment_count']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    181527986 => 0,
    51622513 => 0,
    185431326 => 0,
    140336230 => 0,
    237793809 => 0,
  );
  $handler->display->display_options['filters']['comment_count']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['comment_count']['group_info']['label'] = 'Status der Frage';
  $handler->display->display_options['filters']['comment_count']['group_info']['identifier'] = 'comment_count';
  $handler->display->display_options['filters']['comment_count']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['comment_count']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Frage beantwortet',
      'operator' => '>=',
      'value' => array(
        'value' => '1',
        'min' => '',
        'max' => '',
      ),
    ),
    2 => array(
      'title' => 'Frage unbeantwortet',
      'operator' => '=',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
    ),
  );
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 'link_to_view';
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Full content */
  $handler = $view->new_display('panel_pane', 'Full content', 'full_content');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Fragen an [field_user_fname] [field_user_lname]';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['display_description'] = 'A content pane used on the full content of the question';
  $handler->display->display_options['defaults']['hide_attachment_summary'] = FALSE;
  $handler->display->display_options['hide_attachment_summary'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'sort' => array(
      'bef_format' => 'bef',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
      ),
    ),
    'keys' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_dialogue_topic_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'comment_count' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '',
        'bef_slider_max' => '',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'managed_content';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  /* Feld: Inhalt: ShareThis Link */
  $handler->display->display_options['fields']['sharethis']['id'] = 'sharethis';
  $handler->display->display_options['fields']['sharethis']['table'] = 'node';
  $handler->display->display_options['fields']['sharethis']['field'] = 'sharethis';
  $handler->display->display_options['fields']['sharethis']['label'] = '';
  $handler->display->display_options['fields']['sharethis']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sharethis']['element_default_classes'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['label'] = 'Fieldset Question';
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
    0 => 'field_dialogue_topic',
    1 => 'created',
    2 => 'field_dialogue_sender_name',
    3 => 'body',
    4 => 'field_dialogue_annotation_1',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['classes'] = 'question';
  /* Feld: Feld: Topic */
  $handler->display->display_options['fields']['field_dialogue_topic']['id'] = 'field_dialogue_topic';
  $handler->display->display_options['fields']['field_dialogue_topic']['table'] = 'field_data_field_dialogue_topic';
  $handler->display->display_options['fields']['field_dialogue_topic']['field'] = 'field_dialogue_topic';
  $handler->display->display_options['fields']['field_dialogue_topic']['label'] = 'Thema';
  $handler->display->display_options['fields']['field_dialogue_topic']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_dialogue_topic']['element_wrapper_class'] = 'topic float-right';
  $handler->display->display_options['fields']['field_dialogue_topic']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_topic']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'date_only_short';
  /* Feld: Inhalt: Sender Name */
  $handler->display->display_options['fields']['field_dialogue_sender_name']['id'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['table'] = 'field_data_field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['field'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['label'] = 'Frage von';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dialogue_sender_name']['alter']['text'] = ' [field_dialogue_sender_name]<br/><span class="subline">[created]</span>
';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_sender_name']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['element_wrapper_class'] = 'bubble';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_sender_name']['empty'] = 'anonymous<br/><span class="subline">[created]</span>';
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_class'] = 'content push-bottom-s';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Feld: Feld: Annotation */
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['id'] = 'field_dialogue_annotation_1';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['table'] = 'field_data_field_dialogue_annotation';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['field'] = 'field_dialogue_annotation';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['label'] = 'Anmerkung der Redaktion';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['element_label_class'] = 'small';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['element_wrapper_class'] = 'small annotation push-bottom-m clear';
  $handler->display->display_options['fields']['field_dialogue_annotation_1']['element_default_classes'] = FALSE;
  /* Feld: Global: Ansicht */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'profile_questions_answers';
  $handler->display->display_options['fields']['view']['display'] = 'panel_pane_2';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Beitrags-ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'dialogue' => 'dialogue',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dialogue' => 'dialogue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 'link_to_view';
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Landingpage Parliament */
  $handler = $view->new_display('panel_pane', 'Landingpage Parliament', 'landing_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Fragen an [field_user_fname] [field_user_lname]';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['display_description'] = 'A content pane used on the election landingpage';
  $handler->display->display_options['defaults']['hide_attachment_summary'] = FALSE;
  $handler->display->display_options['hide_attachment_summary'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'bfzgpesxoluceqsd',
  );
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'sort' => array(
      'bef_format' => 'bef',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
      ),
    ),
    'combine' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '<div class="ic-info"><div class="info-title"></div><div class="info-content element-hidden">Infotext</div></div>',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_dialogue_topic_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '<div class="ic-info"><div class="info-title"></div><div class="info-content element-hidden">Infotext</div></div>',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'comment_count' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '',
        'bef_slider_max' => '',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '<div class="ic-info"><div class="info-title"></div><div class="info-content element-hidden">Infotext</div></div>',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'managed_content';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'first';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'zurück';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'last';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'push-bottom-l relative pw-list-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<?php
drupal_add_js(drupal_get_path(\'theme\',\'parliamentwatch\').\'/js/shortlink.js\');
drupal_add_js(drupal_get_path(\'theme\',\'parliamentwatch\').\'/js/hidefilter.js\');
?>
';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Beziehung: Inhalt: Autor */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid_1']['label'] = 'content author';
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['id'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['table'] = 'field_data_field_dialogue_recipient';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['field'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  /* Feld: Inhalt: ShareThis Link */
  $handler->display->display_options['fields']['sharethis']['id'] = 'sharethis';
  $handler->display->display_options['fields']['sharethis']['table'] = 'node';
  $handler->display->display_options['fields']['sharethis']['field'] = 'sharethis';
  $handler->display->display_options['fields']['sharethis']['label'] = '';
  $handler->display->display_options['fields']['sharethis']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sharethis']['element_default_classes'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['label'] = 'Fieldset Question';
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
    0 => 'field_dialogue_topic',
    1 => 'created',
    2 => 'field_dialogue_sender_name',
    3 => 'body',
    4 => 'field_dialogue_annotation_1',
    5 => 'nothing',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['classes'] = 'question';
  /* Feld: Feld: Topic */
  $handler->display->display_options['fields']['field_dialogue_topic']['id'] = 'field_dialogue_topic';
  $handler->display->display_options['fields']['field_dialogue_topic']['table'] = 'field_data_field_dialogue_topic';
  $handler->display->display_options['fields']['field_dialogue_topic']['field'] = 'field_dialogue_topic';
  $handler->display->display_options['fields']['field_dialogue_topic']['label'] = 'Thema';
  $handler->display->display_options['fields']['field_dialogue_topic']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_dialogue_topic']['element_wrapper_class'] = 'topic float-right';
  $handler->display->display_options['fields']['field_dialogue_topic']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_topic']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_dialogue_topic']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'date_only_short';
  /* Feld: Inhalt: Sender Name */
  $handler->display->display_options['fields']['field_dialogue_sender_name']['id'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['table'] = 'field_data_field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['field'] = 'field_dialogue_sender_name';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['label'] = 'Frage von';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dialogue_sender_name']['alter']['text'] = ' [field_dialogue_sender_name]<br/><span class="subline">[created]</span>
';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_sender_name']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['element_wrapper_class'] = 'bubble';
  $handler->display->display_options['fields']['field_dialogue_sender_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_sender_name']['empty'] = 'anonymous<br/><span class="subline">[created]</span>';
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_class'] = 'content push-bottom-s';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Link kopieren';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_type'] = 'span';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'read-more';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'clear';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Feld: Inhalt: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node_1']['id'] = 'edit_node_1';
  $handler->display->display_options['fields']['edit_node_1']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node_1']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node_1']['label'] = '';
  $handler->display->display_options['fields']['edit_node_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node_1']['element_label_colon'] = FALSE;
  /* Feld: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_comment_1' => 'edit_comment_1',
    'edit_node_1' => 'edit_node_1',
    'uid' => 0,
    'nid' => 0,
    'sharethis' => 0,
    'fieldset_1' => 0,
    'field_dialogue_topic' => 0,
    'created' => 0,
    'field_dialogue_sender_name' => 0,
    'body' => 0,
    'field_dialogue_annotation_1' => 0,
    'fieldset_2' => 0,
    'fieldset_3' => 0,
    'field_user_picture' => 0,
    'field_user_fname' => 0,
    'field_user_lname' => 0,
    'created_1' => 0,
    'comment_body' => 0,
    'field_dialogue_annotation' => 0,
    'fieldset' => 0,
    'field_dialogue_tags' => 0,
    'path_1' => 0,
    'fieldset_4' => 0,
    'nothing_1' => 0,
    'path' => 0,
    'php' => 0,
    'php_2' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sortierkriterien: Inhalt: Datum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date Question';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Feld: Parliament (field_parliament) (translated) */
  $handler->display->display_options['arguments']['field_parliament_tid_i18n']['id'] = 'field_parliament_tid_i18n';
  $handler->display->display_options['arguments']['field_parliament_tid_i18n']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['arguments']['field_parliament_tid_i18n']['field'] = 'field_parliament_tid_i18n';
  $handler->display->display_options['arguments']['field_parliament_tid_i18n']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_parliament_tid_i18n']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parliament_tid_i18n']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_parliament_tid_i18n']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parliament_tid_i18n']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parliament_tid_i18n']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parliament_tid_i18n']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid_i18n']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_parliament_tid_i18n']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dialogue' => 'dialogue',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Inhalt: Body (body:summary) */
  $handler->display->display_options['filters']['body_summary']['id'] = 'body_summary';
  $handler->display->display_options['filters']['body_summary']['table'] = 'field_data_body';
  $handler->display->display_options['filters']['body_summary']['field'] = 'body_summary';
  $handler->display->display_options['filters']['body_summary']['operator'] = 'not empty';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 'link_to_view';
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Answers pane */
  $handler = $view->new_display('panel_pane', 'Answers pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_2']['id'] = 'fieldset_2';
  $handler->display->display_options['fields']['fieldset_2']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_2']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_2']['label'] = 'Fieldset Answer';
  $handler->display->display_options['fields']['fieldset_2']['children'] = array(
    0 => 'fieldset_3',
    1 => 'fieldset',
  );
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['classes'] = 'comment answer clearfix';
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['id'] = 'answer-[cid]';
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_3']['id'] = 'fieldset_3';
  $handler->display->display_options['fields']['fieldset_3']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_3']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_3']['label'] = 'Fieldset Answer Inner';
  $handler->display->display_options['fields']['fieldset_3']['children'] = array(
    0 => 'field_user_picture',
    1 => 'field_user_fname',
    2 => 'field_user_lname',
    3 => 'created_1',
    4 => 'field_dialogue_is_standard_reply',
    5 => 'field_dialogue_comment_body',
    6 => 'field_dialogue_annotation',
  );
  $handler->display->display_options['fields']['fieldset_3']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_3']['fieldset']['classes'] = 'content-inner clearfix';
  /* Feld: Benutzer: Profile picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_picture']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_picture']['element_wrapper_class'] = 'float-left push-bottom-s push-right-m';
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'file_view_mode' => 'pw_file_portrait_s',
  );
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname']['element_default_classes'] = FALSE;
  /* Feld: Kommentar: Datum */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'comment';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['relationship'] = 'cid';
  $handler->display->display_options['fields']['created_1']['label'] = '';
  $handler->display->display_options['fields']['created_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created_1']['alter']['text'] = '<h3>
    Antwort von [field_user_fname] [field_user_lname]<br/>
    <span class="subline">[created_1]</span>
</h3>';
  $handler->display->display_options['fields']['created_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created_1']['date_format'] = 'date_only_short';
  /* Feld: Kommentar: Standard reply */
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['id'] = 'field_dialogue_is_standard_reply';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['table'] = 'field_data_field_dialogue_is_standard_reply';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['field'] = 'field_dialogue_is_standard_reply';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['relationship'] = 'cid';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['label'] = '';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['alter']['text'] = 'Standard-Antwort <span class="ic-info ic-right"><span class="info-title"></span><span class="info-content element-hidden">"Standard-Antworten" sind Antworten, in denen Politiker mitteilen, dass sie über abgeordnetenwatch.de grundsätzlich nicht auf Fragen eingehen wollen. Diese werden in der Statistik als "keine Antwort" gewertet.</span></span>';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['element_wrapper_class'] = 'pw-standard-reply';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['empty_zero'] = TRUE;
  /* Feld: Kommentar: Comment Body */
  $handler->display->display_options['fields']['field_dialogue_comment_body']['id'] = 'field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['table'] = 'field_data_field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['field'] = 'field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['relationship'] = 'cid';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['label'] = '';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dialogue_comment_body']['alter']['text'] = '<div class="content clear">[field_dialogue_comment_body]</div>';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_comment_body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_comment_body']['empty'] = '<strong>Bisher ist noch keine Antwort eingetroffen</strong>';
  /* Feld: Feld: Annotation */
  $handler->display->display_options['fields']['field_dialogue_annotation']['id'] = 'field_dialogue_annotation';
  $handler->display->display_options['fields']['field_dialogue_annotation']['table'] = 'field_data_field_dialogue_annotation';
  $handler->display->display_options['fields']['field_dialogue_annotation']['field'] = 'field_dialogue_annotation';
  $handler->display->display_options['fields']['field_dialogue_annotation']['relationship'] = 'cid';
  $handler->display->display_options['fields']['field_dialogue_annotation']['label'] = 'Anmerkung der Redaktion';
  $handler->display->display_options['fields']['field_dialogue_annotation']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_dialogue_annotation']['element_label_class'] = 'small';
  $handler->display->display_options['fields']['field_dialogue_annotation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_annotation']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_dialogue_annotation']['element_wrapper_class'] = 'small annotation clear';
  $handler->display->display_options['fields']['field_dialogue_annotation']['element_default_classes'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['label'] = 'Weitere Informationen zur Antwort';
  $handler->display->display_options['fields']['fieldset']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_dialogue_response_time',
    1 => 'field_dialogue_tags_1',
    2 => 'path_1',
    3 => 'fieldset_4',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'more-info content-inner clearfix';
  $handler->display->display_options['fields']['fieldset']['fieldset']['id'] = 'pw-question-[nid]';
  $handler->display->display_options['fields']['fieldset']['fieldset']['collapsible'] = 1;
  $handler->display->display_options['fields']['fieldset']['fieldset']['collapsed'] = 1;
  /* Feld: Kommentar: Response time */
  $handler->display->display_options['fields']['field_dialogue_response_time']['id'] = 'field_dialogue_response_time';
  $handler->display->display_options['fields']['field_dialogue_response_time']['table'] = 'field_data_field_dialogue_response_time';
  $handler->display->display_options['fields']['field_dialogue_response_time']['field'] = 'field_dialogue_response_time';
  $handler->display->display_options['fields']['field_dialogue_response_time']['relationship'] = 'cid';
  $handler->display->display_options['fields']['field_dialogue_response_time']['label'] = 'Dauer zur eingetroffenen Antwort';
  $handler->display->display_options['fields']['field_dialogue_response_time']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_dialogue_response_time']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_dialogue_response_time']['element_wrapper_class'] = 'pw-response-time';
  $handler->display->display_options['fields']['field_dialogue_response_time']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_response_time']['hide_empty'] = TRUE;
  /* Feld: Feld: Tags */
  $handler->display->display_options['fields']['field_dialogue_tags_1']['id'] = 'field_dialogue_tags_1';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['table'] = 'field_data_field_dialogue_tags';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['field'] = 'field_dialogue_tags';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['label'] = 'Schlagworte';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['element_wrapper_class'] = 'icon-taxonomy';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_tags_1']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['delta_offset'] = '0';
  /* Feld: Content: Path: Print */
  $handler->display->display_options['fields']['path_1']['id'] = 'path_1';
  $handler->display->display_options['fields']['path_1']['table'] = 'node';
  $handler->display->display_options['fields']['path_1']['field'] = 'path';
  $handler->display->display_options['fields']['path_1']['ui_name'] = 'Content: Path: Print';
  $handler->display->display_options['fields']['path_1']['label'] = '';
  $handler->display->display_options['fields']['path_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path_1']['alter']['text'] = 'Frage und Antwort drucken';
  $handler->display->display_options['fields']['path_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['path_1']['alter']['path'] = 'print[path_1]';
  $handler->display->display_options['fields']['path_1']['alter']['link_class'] = 'print-page';
  $handler->display->display_options['fields']['path_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['path_1']['element_default_classes'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_4']['id'] = 'fieldset_4';
  $handler->display->display_options['fields']['fieldset_4']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_4']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_4']['label'] = 'permalink-wrapper';
  $handler->display->display_options['fields']['fieldset_4']['children'] = array(
    0 => 'nothing_1',
    1 => 'php_1',
    2 => 'php',
    3 => 'php_2',
  );
  $handler->display->display_options['fields']['fieldset_4']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_4']['fieldset']['classes'] = 'icon-link';
  $handler->display->display_options['fields']['fieldset_4']['fieldset']['id'] = 'pw-question-path-[nid]';
  /* Feld: Global: Custom text: Headline */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Global: Custom text: Headline';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Permanent-Link zu obenstehender Frage und Antwort';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Feld: Global: PHP: Permalink */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Global: PHP: Permalink';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['php_1']['element_wrapper_class'] = 'permalink';
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
$path = drupal_lookup_path(\'alias\',"node/".$data->nid); 
$path = url($path, array(\'absolute\' => true));
print \'<input type="text" value="\'.$path.\'" readonly />\';
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Feld: Global: PHP: tinyURL */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Global: PHP: tinyURL';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_type'] = 'div';
  $handler->display->display_options['fields']['php']['element_class'] = 'text-field js-hide';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['php']['element_wrapper_class'] = 'shortlink pw-question-link';
  $handler->display->display_options['fields']['php']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$path = drupal_lookup_path(\'alias\',"node/".$data->nid); 
$path = url($path, array(\'absolute\' => true));
print shorten_url($original = $path, $service = \'tinyURL\'); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Global: PHP: trim the link */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Global: PHP: trim the link';
  $handler->display->display_options['fields']['php_2']['label'] = '';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<div class="shorten"><span id="shortlink-<?php print $row->nid; ?>"><?php print t(\'trim the link\'); ?></span></div>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Feld: excluded | edit answer */
  $handler->display->display_options['fields']['edit_comment']['id'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['edit_comment']['field'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['relationship'] = 'cid';
  $handler->display->display_options['fields']['edit_comment']['ui_name'] = 'excluded | edit answer';
  $handler->display->display_options['fields']['edit_comment']['label'] = '';
  $handler->display->display_options['fields']['edit_comment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_comment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_comment']['text'] = 'edit answer';
  $handler->display->display_options['fields']['edit_comment']['destination'] = TRUE;
  /* Feld: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_comment' => 'edit_comment',
    'edit_node' => 'edit_node',
    'uid' => 0,
    'nid' => 0,
    'sharethis' => 0,
    'fieldset_1' => 0,
    'field_dialogue_topic' => 0,
    'created' => 0,
    'field_dialogue_sender_name' => 0,
    'body' => 0,
    'field_dialogue_tags' => 0,
    'fieldset_2' => 0,
    'fieldset_3' => 0,
    'fieldset_5' => 0,
    'field_user_picture' => 0,
    'field_image_copyright' => 0,
    'field_user_fname' => 0,
    'field_user_lname' => 0,
    'created_1' => 0,
    'comment_body' => 0,
    'fieldset' => 0,
    'field_dialogue_topic_1' => 0,
    'path_1' => 0,
    'fieldset_4' => 0,
    'nothing_1' => 0,
    'path' => 0,
    'php' => 0,
    'php_2' => 0,
  );

  /* Display: Answers pane full content */
  $handler = $view->new_display('panel_pane', 'Answers pane full content', 'panel_pane_2');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="comment">  	
    <div class="content-inner">
        <strong><?php print t(\'Bisher ist noch keine Antwort eingetroffen\'); ?></strong>
    </div>
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'php_code';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_2']['id'] = 'fieldset_2';
  $handler->display->display_options['fields']['fieldset_2']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_2']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_2']['label'] = 'Fieldset Answer';
  $handler->display->display_options['fields']['fieldset_2']['children'] = array(
    0 => 'fieldset_3',
    1 => 'fieldset',
  );
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['classes'] = 'comment answer clearfix';
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['id'] = 'answer-[cid]';
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_3']['id'] = 'fieldset_3';
  $handler->display->display_options['fields']['fieldset_3']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_3']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_3']['label'] = 'Fieldset Answer Inner';
  $handler->display->display_options['fields']['fieldset_3']['children'] = array(
    0 => 'field_user_picture',
    1 => 'field_user_fname',
    2 => 'field_user_lname',
    3 => 'created_1',
    4 => 'field_dialogue_is_standard_reply',
    5 => 'field_dialogue_comment_body',
    6 => 'field_dialogue_annotation',
  );
  $handler->display->display_options['fields']['fieldset_3']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_3']['fieldset']['classes'] = 'content-inner clearfix';
  /* Feld: Benutzer: Profile picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_picture']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_picture']['element_wrapper_class'] = 'float-left push-bottom-s push-right-m';
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'file_view_mode' => 'pw_file_portrait_s',
  );
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname']['element_default_classes'] = FALSE;
  /* Feld: Kommentar: Datum */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'comment';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['relationship'] = 'cid';
  $handler->display->display_options['fields']['created_1']['label'] = '';
  $handler->display->display_options['fields']['created_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created_1']['alter']['text'] = '<h3>
    Antwort von [field_user_fname] [field_user_lname]<br/>
    <span class="subline">[created_1]</span>
</h3>';
  $handler->display->display_options['fields']['created_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created_1']['date_format'] = 'date_only_short';
  /* Feld: Kommentar: Standard reply */
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['id'] = 'field_dialogue_is_standard_reply';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['table'] = 'field_data_field_dialogue_is_standard_reply';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['field'] = 'field_dialogue_is_standard_reply';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['relationship'] = 'cid';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['label'] = '';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['alter']['text'] = 'Standard-Antwort <span class="ic-info ic-right"><span class="info-title"></span><span class="info-content element-hidden">"Standard-Antworten" sind Antworten, in denen Politiker mitteilen, dass sie über abgeordnetenwatch.de grundsätzlich nicht auf Fragen eingehen wollen. Diese werden in der Statistik als "keine Antwort" gewertet.</span></span>';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['element_wrapper_class'] = 'pw-standard-reply';
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_dialogue_is_standard_reply']['empty_zero'] = TRUE;
  /* Feld: Kommentar: Comment Body */
  $handler->display->display_options['fields']['field_dialogue_comment_body']['id'] = 'field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['table'] = 'field_data_field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['field'] = 'field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['relationship'] = 'cid';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['label'] = '';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dialogue_comment_body']['alter']['text'] = '<div class="content clear">[field_dialogue_comment_body]</div>';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_comment_body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_comment_body']['empty'] = '<strong>Bisher ist noch keine Antwort eingetroffen</strong>';
  /* Feld: Feld: Annotation */
  $handler->display->display_options['fields']['field_dialogue_annotation']['id'] = 'field_dialogue_annotation';
  $handler->display->display_options['fields']['field_dialogue_annotation']['table'] = 'field_data_field_dialogue_annotation';
  $handler->display->display_options['fields']['field_dialogue_annotation']['field'] = 'field_dialogue_annotation';
  $handler->display->display_options['fields']['field_dialogue_annotation']['relationship'] = 'cid';
  $handler->display->display_options['fields']['field_dialogue_annotation']['label'] = 'Anmerkung der Redaktion';
  $handler->display->display_options['fields']['field_dialogue_annotation']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_dialogue_annotation']['element_label_class'] = 'small';
  $handler->display->display_options['fields']['field_dialogue_annotation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_annotation']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_dialogue_annotation']['element_wrapper_class'] = 'small annotation clear';
  $handler->display->display_options['fields']['field_dialogue_annotation']['element_default_classes'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['label'] = 'Weitere Informationen zur Antwort';
  $handler->display->display_options['fields']['fieldset']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_dialogue_response_time',
    1 => 'field_dialogue_tags_1',
    2 => 'path_1',
    3 => 'fieldset_4',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'more-info content-inner clearfix';
  $handler->display->display_options['fields']['fieldset']['fieldset']['id'] = 'pw-question-[nid]';
  $handler->display->display_options['fields']['fieldset']['fieldset']['collapsible'] = 1;
  /* Feld: Kommentar: Response time */
  $handler->display->display_options['fields']['field_dialogue_response_time']['id'] = 'field_dialogue_response_time';
  $handler->display->display_options['fields']['field_dialogue_response_time']['table'] = 'field_data_field_dialogue_response_time';
  $handler->display->display_options['fields']['field_dialogue_response_time']['field'] = 'field_dialogue_response_time';
  $handler->display->display_options['fields']['field_dialogue_response_time']['relationship'] = 'cid';
  $handler->display->display_options['fields']['field_dialogue_response_time']['label'] = 'Dauer zur eingetroffenen Antwort';
  $handler->display->display_options['fields']['field_dialogue_response_time']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_dialogue_response_time']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_dialogue_response_time']['element_wrapper_class'] = 'pw-response-time';
  $handler->display->display_options['fields']['field_dialogue_response_time']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_response_time']['hide_empty'] = TRUE;
  /* Feld: Feld: Tags */
  $handler->display->display_options['fields']['field_dialogue_tags_1']['id'] = 'field_dialogue_tags_1';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['table'] = 'field_data_field_dialogue_tags';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['field'] = 'field_dialogue_tags';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['label'] = 'Schlagworte';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['element_wrapper_class'] = 'icon-taxonomy';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_tags_1']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_dialogue_tags_1']['delta_offset'] = '0';
  /* Feld: Content: Path: Print */
  $handler->display->display_options['fields']['path_1']['id'] = 'path_1';
  $handler->display->display_options['fields']['path_1']['table'] = 'node';
  $handler->display->display_options['fields']['path_1']['field'] = 'path';
  $handler->display->display_options['fields']['path_1']['ui_name'] = 'Content: Path: Print';
  $handler->display->display_options['fields']['path_1']['label'] = '';
  $handler->display->display_options['fields']['path_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['path_1']['alter']['text'] = 'Frage und Antwort drucken';
  $handler->display->display_options['fields']['path_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['path_1']['alter']['path'] = 'print[path_1]';
  $handler->display->display_options['fields']['path_1']['alter']['link_class'] = 'print-page';
  $handler->display->display_options['fields']['path_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['path_1']['element_default_classes'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_4']['id'] = 'fieldset_4';
  $handler->display->display_options['fields']['fieldset_4']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_4']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_4']['label'] = 'permalink-wrapper';
  $handler->display->display_options['fields']['fieldset_4']['children'] = array(
    0 => 'nothing_1',
    1 => 'php_1',
    2 => 'php',
    3 => 'php_2',
  );
  $handler->display->display_options['fields']['fieldset_4']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_4']['fieldset']['classes'] = 'icon-link';
  $handler->display->display_options['fields']['fieldset_4']['fieldset']['id'] = 'pw-question-path-[nid]';
  /* Feld: Global: Custom text: Headline */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Global: Custom text: Headline';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Permanent-Link zu obenstehender Frage und Antwort';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Feld: Global: PHP: Permalink */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Global: PHP: Permalink';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['php_1']['element_wrapper_class'] = 'permalink';
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
$path = drupal_lookup_path(\'alias\',"node/".$data->nid); 
$path = url($path, array(\'absolute\' => true));
print \'<input type="text" value="\'.$path.\'" readonly />\';
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Feld: Global: PHP: tinyURL */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Global: PHP: tinyURL';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_type'] = 'div';
  $handler->display->display_options['fields']['php']['element_class'] = 'text-field js-hide';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['php']['element_wrapper_class'] = 'shortlink pw-question-link';
  $handler->display->display_options['fields']['php']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$path = drupal_lookup_path(\'alias\',"node/".$data->nid); 
$path = url($path, array(\'absolute\' => true));
print shorten_url($original = $path, $service = \'tinyURL\'); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Global: PHP: trim the link */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Global: PHP: trim the link';
  $handler->display->display_options['fields']['php_2']['label'] = '';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<div class="shorten"><span id="shortlink-<?php print $row->nid; ?>"><?php print t(\'trim the link\'); ?></span></div>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Feld: excluded | edit answer */
  $handler->display->display_options['fields']['edit_comment']['id'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['edit_comment']['field'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['relationship'] = 'cid';
  $handler->display->display_options['fields']['edit_comment']['ui_name'] = 'excluded | edit answer';
  $handler->display->display_options['fields']['edit_comment']['label'] = '';
  $handler->display->display_options['fields']['edit_comment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_comment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_comment']['text'] = 'edit answer';
  $handler->display->display_options['fields']['edit_comment']['destination'] = TRUE;
  /* Feld: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_comment' => 'edit_comment',
    'edit_node' => 'edit_node',
    'uid' => 0,
    'nid' => 0,
    'sharethis' => 0,
    'fieldset_1' => 0,
    'field_dialogue_topic' => 0,
    'created' => 0,
    'field_dialogue_sender_name' => 0,
    'body' => 0,
    'field_dialogue_tags' => 0,
    'fieldset_2' => 0,
    'fieldset_3' => 0,
    'fieldset_5' => 0,
    'field_user_picture' => 0,
    'field_image_copyright' => 0,
    'field_user_fname' => 0,
    'field_user_lname' => 0,
    'created_1' => 0,
    'comment_body' => 0,
    'fieldset' => 0,
    'field_dialogue_topic_1' => 0,
    'path_1' => 0,
    'fieldset_4' => 0,
    'nothing_1' => 0,
    'path' => 0,
    'php' => 0,
    'php_2' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Kommentar: Beitrags-ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'comment';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'cid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $export['profile_questions_answers'] = $view;

  $view = new view();
  $view->name = 'pw_dialogue_answers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'PW Dialogue answers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'PW Dialogue answers';
  $handler->display->display_options['css_class'] = 'view-answers';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'comment answer push-bottom-l';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Beziehung: Kommentar: Inhalt */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Beziehung: Entity Reference: Entität, auf die verwiesen wird */
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['id'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['table'] = 'field_data_field_dialogue_recipient';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['field'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['relationship'] = 'nid';
  $handler->display->display_options['relationships']['field_dialogue_recipient_target_id']['required'] = TRUE;
  /* Beziehung: Benutzer: Profile picture (field_user_picture:fid) */
  $handler->display->display_options['relationships']['field_user_picture_fid']['id'] = 'field_user_picture_fid';
  $handler->display->display_options['relationships']['field_user_picture_fid']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['relationships']['field_user_picture_fid']['field'] = 'field_user_picture_fid';
  $handler->display->display_options['relationships']['field_user_picture_fid']['relationship'] = 'field_dialogue_recipient_target_id';
  /* Feld: excluded | uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['uid']['ui_name'] = 'excluded | uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'sharethis',
    1 => 'field_user_picture',
    2 => 'nothing',
    3 => 'field_user_fname',
    4 => 'field_user_lname',
    5 => 'field_user_party',
    6 => 'created',
    7 => 'nothing_1',
    8 => 'field_dialogue_is_standard_reply',
    9 => 'fieldset_1',
    10 => 'view_user',
    11 => 'field_dialogue_comment_body',
    12 => 'field_dialogue_annotation',
    13 => 'view_node',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'content-inner';
  /* Feld: Inhalt: ShareThis Link */
  $handler->display->display_options['fields']['sharethis']['id'] = 'sharethis';
  $handler->display->display_options['fields']['sharethis']['table'] = 'node';
  $handler->display->display_options['fields']['sharethis']['field'] = 'sharethis';
  $handler->display->display_options['fields']['sharethis']['relationship'] = 'nid';
  $handler->display->display_options['fields']['sharethis']['label'] = '';
  $handler->display->display_options['fields']['sharethis']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sharethis']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sharethis']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Profile picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_picture']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_picture']['element_wrapper_class'] = 'float-left push-bottom-xs push-right-m pw_portrait_s';
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'file_view_mode' => 'pw_file_portrait_s',
  );
  /* Feld: h3 */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'h3';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h3>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['text'] = '[field_user_lname],';
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Party */
  $handler->display->display_options['fields']['field_user_party']['id'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['fields']['field_user_party']['field'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_party']['label'] = '';
  $handler->display->display_options['fields']['field_user_party']['alter']['text'] = '[field_user_fname] [field_user_lname], [field_user_party]';
  $handler->display->display_options['fields']['field_user_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_party']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_party']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party']['delta_offset'] = '0';
  /* Feld: Inhalt: Datum */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'nid';
  $handler->display->display_options['fields']['created']['label'] = 'zu einer Frage von ';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['created']['element_wrapper_class'] = 'subline';
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'date_only_short';
  /* Feld: /h3 */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = '/h3';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '</h3>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
    0 => 'field_user_questions_get',
    1 => 'field_user_answers_give',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['classes'] = 'small light push-bottom-m';
  /* Feld: Benutzer: Questions Get */
  $handler->display->display_options['fields']['field_user_questions_get']['id'] = 'field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['table'] = 'field_data_field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['field'] = 'field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_questions_get']['label'] = '';
  $handler->display->display_options['fields']['field_user_questions_get']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_questions_get']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_questions_get']['alter']['text'] = '[field_user_questions_get],';
  $handler->display->display_options['fields']['field_user_questions_get']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_questions_get']['settings'] = array(
    'thousand_separator' => '.',
    'prefix_suffix' => 1,
  );
  /* Feld: Benutzer: Answers Give */
  $handler->display->display_options['fields']['field_user_answers_give']['id'] = 'field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['table'] = 'field_data_field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['field'] = 'field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['field_user_answers_give']['label'] = '';
  $handler->display->display_options['fields']['field_user_answers_give']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_answers_give']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_answers_give']['settings'] = array(
    'thousand_separator' => '.',
    'prefix_suffix' => 1,
  );
  /* Feld: Benutzer: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['element_type'] = 'p';
  $handler->display->display_options['fields']['view_user']['element_class'] = 'link-profile';
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_user']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_user']['text'] = 'Profil besuchen';
  /* Feld: Kommentar: Comment Body */
  $handler->display->display_options['fields']['field_dialogue_comment_body']['id'] = 'field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['table'] = 'field_data_field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['field'] = 'field_dialogue_comment_body';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['label'] = '';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_comment_body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['element_wrapper_class'] = 'clear';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_dialogue_comment_body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_dialogue_comment_body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Feld: Inhalt: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'nid';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_type'] = 'span';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'read-more';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'bg-white clear';
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Frage und ganze Antwort lesen';
  $handler->display->display_options['fields']['view_node']['node_in_colorbox_width'] = '800';
  $handler->display->display_options['fields']['view_node']['node_in_colorbox_height'] = '1600';
  $handler->display->display_options['fields']['view_node']['node_in_colorbox_rel'] = '';
  /* Feld: excluded | edit answer */
  $handler->display->display_options['fields']['edit_comment']['id'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['edit_comment']['field'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['ui_name'] = 'excluded | edit answer';
  $handler->display->display_options['fields']['edit_comment']['label'] = '';
  $handler->display->display_options['fields']['edit_comment']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_comment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_comment']['text'] = 'edit answer';
  /* Feld: excluded | edit recipient */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'field_dialogue_recipient_target_id';
  $handler->display->display_options['fields']['edit_node']['ui_name'] = 'excluded | edit recipient';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'edit recipient';
  /* Feld: excluded | edit question */
  $handler->display->display_options['fields']['edit_node_1']['id'] = 'edit_node_1';
  $handler->display->display_options['fields']['edit_node_1']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node_1']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node_1']['relationship'] = 'nid';
  $handler->display->display_options['fields']['edit_node_1']['ui_name'] = 'excluded | edit question';
  $handler->display->display_options['fields']['edit_node_1']['label'] = '';
  $handler->display->display_options['fields']['edit_node_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node_1']['text'] = 'edit question';
  /* Feld: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_comment' => 'edit_comment',
    'edit_node' => 'edit_node',
    'edit_node_1' => 'edit_node_1',
    'field_user_parliament' => 'field_user_parliament',
    'field_dialogue_recipient' => 0,
    'field_pw_parmliament' => 0,
    'field_dialogue_annotation' => 0,
  );
  /* Sortierkriterien: Kommentar: Datum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'comment';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Kontextfilter: Feld: Parliament (field_parliament) */
  $handler->display->display_options['arguments']['field_parliament_tid']['id'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['table'] = 'field_data_field_parliament';
  $handler->display->display_options['arguments']['field_parliament_tid']['field'] = 'field_parliament_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_parliament_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_parliament_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parliament_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parliament_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_parliament_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_parliament_tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  /* Filterkriterium: Kommentar: Bestätigt */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Inhalt: Veröffentlicht */
  $handler->display->display_options['filters']['status_node']['id'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['table'] = 'node';
  $handler->display->display_options['filters']['status_node']['field'] = 'status';
  $handler->display->display_options['filters']['status_node']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_node']['value'] = 1;
  $handler->display->display_options['filters']['status_node']['group'] = 1;
  $handler->display->display_options['filters']['status_node']['expose']['operator'] = FALSE;
  /* Filterkriterium: Inhalt: Typ */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dialogue' => 'dialogue',
  );
  /* Filterkriterium: Kommentar: Comment Body (field_dialogue_comment_body:summary) */
  $handler->display->display_options['filters']['field_dialogue_comment_body_summary']['id'] = 'field_dialogue_comment_body_summary';
  $handler->display->display_options['filters']['field_dialogue_comment_body_summary']['table'] = 'field_data_field_dialogue_comment_body';
  $handler->display->display_options['filters']['field_dialogue_comment_body_summary']['field'] = 'field_dialogue_comment_body_summary';
  $handler->display->display_options['filters']['field_dialogue_comment_body_summary']['operator'] = 'not empty';
  /* Filterkriterium: Kommentar: Standard reply (field_dialogue_is_standard_reply) */
  $handler->display->display_options['filters']['field_dialogue_is_standard_reply_value']['id'] = 'field_dialogue_is_standard_reply_value';
  $handler->display->display_options['filters']['field_dialogue_is_standard_reply_value']['table'] = 'field_data_field_dialogue_is_standard_reply';
  $handler->display->display_options['filters']['field_dialogue_is_standard_reply_value']['field'] = 'field_dialogue_is_standard_reply_value';
  $handler->display->display_options['filters']['field_dialogue_is_standard_reply_value']['value'] = array(
    0 => '0',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $export['pw_dialogue_answers'] = $view;

  return $export;
}
