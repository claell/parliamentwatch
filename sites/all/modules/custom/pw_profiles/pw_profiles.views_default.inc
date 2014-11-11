<?php
/**
 * @file
 * pw_profiles.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_profiles_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'calendar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'PW User Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Calendar';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'weiterlesen';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '500';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'pw-list-item clearfix';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Kopfbereich: Global: Textbereich */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Beziehung: Inhalt: Autor */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Feld: Inhalt: Date */
  $handler->display->display_options['fields']['field_calendar_entry_date']['id'] = 'field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date']['table'] = 'field_data_field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date']['field'] = 'field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date']['label'] = '';
  $handler->display->display_options['fields']['field_calendar_entry_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_calendar_entry_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sortierkriterien: Inhalt: Datum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'calendar_entry' => 'calendar_entry',
  );

  /* Display: Profile Calendar */
  $handler = $view->new_display('block', 'Profile Calendar', 'profile_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Wahlkampftermine von [field_user_fname] [field_user_lname]';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'go to full calendar';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: sharethis link */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'sharethis link';
  $handler->display->display_options['header']['area']['content'] = '<div id="calendar" class="add-sharethis" title="<?php print t(\'Calendar of\'); ?> [field_user_fname] [field_user_lname], [field_user_party]"></div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Fußbereich: link to calendar page */
  $handler->display->display_options['footer']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['footer']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['footer']['area_text_custom']['ui_name'] = 'link to calendar page';
  $handler->display->display_options['footer']['area_text_custom']['content'] = '<a href="/profile/[name]/calendar" class="link-calendar float-right">Alle Termine anzeigen</a>';
  $handler->display->display_options['footer']['area_text_custom']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Beziehung: Inhalt: Autor */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['label'] = 'Datum und Uhrzeit';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_calendar_entry_date',
    1 => 'field_calendar_entry_date_1',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'grid-2 alpha';
  /* Feld: Inhalt: Date */
  $handler->display->display_options['fields']['field_calendar_entry_date']['id'] = 'field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date']['table'] = 'field_data_field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date']['field'] = 'field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date']['label'] = '';
  $handler->display->display_options['fields']['field_calendar_entry_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_calendar_entry_date']['settings'] = array(
    'format_type' => 'date_only_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Time */
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['id'] = 'field_calendar_entry_date_1';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['table'] = 'field_data_field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['field'] = 'field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['ui_name'] = 'Time';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['alter']['text'] = '[field_calendar_entry_date_1] Uhr';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['element_wrapper_class'] = 'small';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['settings'] = array(
    'format_type' => 'time_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['label'] = 'Fieldset Data';
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
    0 => 'field_user_fname',
    1 => 'field_user_lname',
    2 => 'field_user_party',
    3 => 'name',
    4 => 'title',
    5 => 'field_calendar_entry_address',
    6 => 'title_1',
    7 => 'fieldset_2',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['classes'] = 'grid-6 omega';
  /* Feld: Excluded | First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_fname']['ui_name'] = 'Excluded | First Name';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  /* Feld: Excluded | Last Name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_lname']['ui_name'] = 'Excluded | Last Name';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  /* Feld: Excluded | Party */
  $handler->display->display_options['fields']['field_user_party']['id'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['fields']['field_user_party']['field'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_party']['ui_name'] = 'Excluded | Party';
  $handler->display->display_options['fields']['field_user_party']['label'] = '';
  $handler->display->display_options['fields']['field_user_party']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_party']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party']['delta_offset'] = '0';
  /* Feld: Excluded | Author Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['ui_name'] = 'Excluded | Author Name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  /* Feld: Inhalt: Address */
  $handler->display->display_options['fields']['field_calendar_entry_address']['id'] = 'field_calendar_entry_address';
  $handler->display->display_options['fields']['field_calendar_entry_address']['table'] = 'field_data_field_calendar_entry_address';
  $handler->display->display_options['fields']['field_calendar_entry_address']['field'] = 'field_calendar_entry_address';
  $handler->display->display_options['fields']['field_calendar_entry_address']['label'] = '';
  $handler->display->display_options['fields']['field_calendar_entry_address']['alter']['text'] = '<div class="vcard">
    <div class="adr">
        <span class="street-address">[field_calendar_entry_address-thoroughfare]</span>
        <span class="locality">[field_calendar_entry_address-dependent_locality]</span>, 
        <span class="postal-code">[field_calendar_entry_address-postal_code]</span>, 
        <span class="country-name">[field_calendar_entry_address]</span>
     </div>
</div>


';
  $handler->display->display_options['fields']['field_calendar_entry_address']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_calendar_entry_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_calendar_entry_address']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_calendar_entry_address']['element_wrapper_class'] = 'small push-bottom-xs';
  $handler->display->display_options['fields']['field_calendar_entry_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_calendar_entry_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_calendar_entry_address']['type'] = 'addressfield_linear';
  $handler->display->display_options['fields']['field_calendar_entry_address']['settings'] = array(
    'components' => array(
      'thoroughfare' => 'thoroughfare',
      'premise' => 'premise',
      'locality' => 'locality',
      'administrative_area' => 'administrative_area',
      'postal_code' => 'postal_code',
      'country' => 'country',
    ),
    'separator' => ', ',
  );
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_2']['id'] = 'fieldset_2';
  $handler->display->display_options['fields']['fieldset_2']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_2']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_2']['label'] = 'Mehr Informationen zu diesen Termin';
  $handler->display->display_options['fields']['fieldset_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['fieldset_2']['children'] = array(
    0 => 'body',
  );
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['collapsible'] = 1;
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['collapsed'] = 1;
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Benutzer-ID des Autors */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: Calendar Page */
  $handler = $view->new_display('page', 'Calendar Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Calendar Page for sharing';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: sharethis link */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['ui_name'] = 'sharethis link';
  $handler->display->display_options['header']['area']['content'] = '<div class="add-sharethis" title="<?php print t(\'Calendar of\'); ?> [field_user_fname] [field_user_lname], [field_user_party]"></div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Kopfbereich: Global: Ansichtsbereich */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['empty'] = TRUE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'user_profile_fields:short_profile_premium_sub';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  /* Kopfbereich: Global: Textbereich */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['content'] = '<h3><?php print t(\'Calendar of\'); ?> [field_user_fname] [field_user_lname], [field_user_party]</h3>';
  $handler->display->display_options['header']['area_1']['format'] = 'php_code';
  $handler->display->display_options['header']['area_1']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Fußbereich: Global: Textbereich */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="link-profile">[view_user]</div>';
  $handler->display->display_options['footer']['area']['format'] = 'managed_content';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: ShareThis Link */
  $handler->display->display_options['fields']['sharethis']['id'] = 'sharethis';
  $handler->display->display_options['fields']['sharethis']['table'] = 'node';
  $handler->display->display_options['fields']['sharethis']['field'] = 'sharethis';
  $handler->display->display_options['fields']['sharethis']['label'] = '';
  $handler->display->display_options['fields']['sharethis']['element_label_colon'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['label'] = 'Datum und Uhrzeit';
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
    0 => 'field_calendar_entry_date',
    1 => 'field_calendar_entry_date_1',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['classes'] = 'grid-2 alpha';
  /* Feld: Inhalt: Date */
  $handler->display->display_options['fields']['field_calendar_entry_date']['id'] = 'field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date']['table'] = 'field_data_field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date']['field'] = 'field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date']['label'] = '';
  $handler->display->display_options['fields']['field_calendar_entry_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_calendar_entry_date']['settings'] = array(
    'format_type' => 'date_only_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Inhalt: Date */
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['id'] = 'field_calendar_entry_date_1';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['table'] = 'field_data_field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['field'] = 'field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['element_wrapper_class'] = 'small';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['settings'] = array(
    'format_type' => 'time_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_2']['id'] = 'fieldset_2';
  $handler->display->display_options['fields']['fieldset_2']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_2']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_2']['label'] = 'Fieldset Data';
  $handler->display->display_options['fields']['fieldset_2']['children'] = array(
    0 => 'field_user_fname',
    1 => 'field_user_lname',
    2 => 'field_user_party',
    3 => 'title',
    4 => 'field_calendar_entry_address',
    5 => 'fieldset',
  );
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['classes'] = 'grid-6 omega';
  /* Feld: Excluded | First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_fname']['ui_name'] = 'Excluded | First Name';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  /* Feld: Excluded | Last Name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_lname']['ui_name'] = 'Excluded | Last Name';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  /* Feld: Excluded | Party */
  $handler->display->display_options['fields']['field_user_party']['id'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['fields']['field_user_party']['field'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_party']['ui_name'] = 'Excluded | Party';
  $handler->display->display_options['fields']['field_user_party']['label'] = '';
  $handler->display->display_options['fields']['field_user_party']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_party']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party']['delta_offset'] = '0';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  /* Feld: Inhalt: Address */
  $handler->display->display_options['fields']['field_calendar_entry_address']['id'] = 'field_calendar_entry_address';
  $handler->display->display_options['fields']['field_calendar_entry_address']['table'] = 'field_data_field_calendar_entry_address';
  $handler->display->display_options['fields']['field_calendar_entry_address']['field'] = 'field_calendar_entry_address';
  $handler->display->display_options['fields']['field_calendar_entry_address']['label'] = '';
  $handler->display->display_options['fields']['field_calendar_entry_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_calendar_entry_address']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_calendar_entry_address']['element_wrapper_class'] = 'small push-bottom-xs';
  $handler->display->display_options['fields']['field_calendar_entry_address']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_calendar_entry_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_calendar_entry_address']['type'] = 'addressfield_linear';
  $handler->display->display_options['fields']['field_calendar_entry_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['label'] = 'Mehr Informationen zu diesen Termin';
  $handler->display->display_options['fields']['fieldset']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'body',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['collapsible'] = 1;
  $handler->display->display_options['fields']['fieldset']['fieldset']['collapsed'] = 1;
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '100',
  );
  /* Feld: Excluded | Edit */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['ui_name'] = 'Excluded | Edit';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Feld: Excluded | Delete */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['ui_name'] = 'Excluded | Delete';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Feld: Global: Contextual Links */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'nothing' => 'nothing',
    'nid' => 0,
    'uid' => 0,
    'field_user_fname' => 0,
    'field_user_lname' => 0,
    'field_user_party' => 0,
    'name' => 0,
    'php' => 0,
    'sharethis' => 0,
    'field_calendar_entry_date' => 0,
    'title' => 0,
    'field_calendar_entry_address' => 0,
    'fieldset' => 0,
    'body' => 0,
  );
  /* Feld: Excluded | User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'uid';
  $handler->display->display_options['fields']['view_user']['ui_name'] = 'Excluded | User: Link';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_user']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['view_user']['element_wrapper_class'] = 'link-profile';
  $handler->display->display_options['fields']['view_user']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_user']['text'] = 'zum vollständigen Profil';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Benutzer-ID des Autors */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['path'] = 'profile/%/calendar';

  /* Display: Back to Calendar Block */
  $handler = $view->new_display('block', 'Back to Calendar Block', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Small Block for Calendar Entry Footer Section to go back to main Calendar';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Excluded|Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['ui_name'] = 'Excluded|Name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Feld: Inhalt: Benutzer-ID des Autors */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = 'zum vollständigen Kalender';
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['path'] = 'profile/[name]/calendar';
  $handler->display->display_options['fields']['uid']['alter']['link_class'] = 'link-calendar';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['uid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Inhalt: Benutzer-ID des Autors */
  $handler->display->display_options['fields']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['fields']['uid_1']['table'] = 'node';
  $handler->display->display_options['fields']['uid_1']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_1']['label'] = '';
  $handler->display->display_options['fields']['uid_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid_1']['alter']['text'] = 'zum vollständigen Profil';
  $handler->display->display_options['fields']['uid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid_1']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['uid_1']['element_wrapper_class'] = 'link-profile';
  $handler->display->display_options['fields']['uid_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Benutzer-ID des Autors */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = TRUE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: Calendar Admin  View */
  $handler = $view->new_display('block', 'Calendar Admin  View', 'calendar_admin_block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    51622513 => '51622513',
    178386088 => '178386088',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_calendar_entry_date' => 'field_calendar_entry_date',
    'title' => 'title',
    'delete_node' => 'delete_node',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_calendar_entry_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['label'] = 'Calendar Admin';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<fieldset>
<legend><span class="fieldset-legend"><?php print t("Edit Calendar") ?></span></legend>
<div class="fieldset-wrapper">
<a href="<?php
Global $base_url;
$cpath = explode(\'/\',current_path());
$path_uid = $cpath[1];
$base_url;
$link =$base_url."/node/add/calendar-entry?width=800&height=600&destination=user/".$path_uid."/edit";
print_r($link);
?>" class="colorbox-node init-colorbox-processed-processed"><?php print t(\'+ Add Calendar Entry\'); ?></a>
</div>
</fieldset>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Excluded | nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Excluded | nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  /* Feld: Excluded | Pfad */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['ui_name'] = 'Excluded | Pfad';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Feld: Inhalt: Date */
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['id'] = 'field_calendar_entry_date_1';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['table'] = 'field_data_field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['field'] = 'field_calendar_entry_date';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['label'] = 'Datum';
  $handler->display->display_options['fields']['field_calendar_entry_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  /* Feld: Excluded | Author UID */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['ui_name'] = 'Excluded | Author UID';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Rewritten | Edit */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Rewritten | Edit';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Bearbeiten';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'node/[nid]/edit?width=800&height=600&destination=user/[uid]/edit';
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['link_class'] = 'colorbox-node init-colorbox-processed-processed';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Feld: Rewritten | Delete */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Rewritten | Delete';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'Löschen';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'node/[nid]/delete?width=400&height=100&destination=user/[uid]/edit?';
  $handler->display->display_options['fields']['nothing_2']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['link_class'] = 'colorbox-node init-colorbox-processed-processed';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Inhalt: Benutzer-ID des Autors */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
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
    'calendar_entry' => 'calendar_entry',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $export['calendar'] = $view;

  $view = new view();
  $view->name = 'constituency_for_the_profile';
  $view->description = 'A list of politicians in a slider';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'PW Same Constituency for the profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Weitere Kandidierende im Wahlkreis [field_user_constituency]';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'weiterlesen';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = '0';
  $handler->display->display_options['style_options']['visible'] = '';
  $handler->display->display_options['style_options']['auto'] = '3';
  $handler->display->display_options['style_options']['autoPause'] = 0;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Beziehung: Benutzer: Constituency (field_user_constituency) */
  $handler->display->display_options['relationships']['field_user_constituency_tid']['id'] = 'field_user_constituency_tid';
  $handler->display->display_options['relationships']['field_user_constituency_tid']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['relationships']['field_user_constituency_tid']['field'] = 'field_user_constituency_tid';
  /* Feld: Exluded | User Constituency */
  $handler->display->display_options['fields']['field_user_constituency']['id'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['field'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['ui_name'] = 'Exluded | User Constituency';
  $handler->display->display_options['fields']['field_user_constituency']['label'] = '';
  $handler->display->display_options['fields']['field_user_constituency']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_constituency']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_constituency']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_constituency']['delta_offset'] = '0';
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_lname']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: Party */
  $handler->display->display_options['fields']['field_user_party']['id'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['fields']['field_user_party']['field'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['label'] = '';
  $handler->display->display_options['fields']['field_user_party']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_party']['alter']['text'] = '[field_user_fname] [field_user_lname],[field_user_party]';
  $handler->display->display_options['fields']['field_user_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_party']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party']['delta_offset'] = '0';
  /* Feld: Benutzer: Questions Get */
  $handler->display->display_options['fields']['field_user_questions_get']['id'] = 'field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['table'] = 'field_data_field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['field'] = 'field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['label'] = '';
  $handler->display->display_options['fields']['field_user_questions_get']['alter']['text'] = '[field_user_questions_get] Fragen';
  $handler->display->display_options['fields']['field_user_questions_get']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_questions_get']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Benutzer: Answers Give */
  $handler->display->display_options['fields']['field_user_answers_give']['id'] = 'field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['table'] = 'field_data_field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['field'] = 'field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['label'] = '';
  $handler->display->display_options['fields']['field_user_answers_give']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_answers_give']['alter']['text'] = '[field_user_answers_give] Answers';
  $handler->display->display_options['fields']['field_user_answers_give']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_answers_give']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Benutzer: Profile picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'file_view_mode' => 'pw_file_portrait_s',
  );
  /* Sortierkriterien: Benutzer: Erstellungsdatum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filterkriterium: Benutzer: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: User Constituency Block */
  $handler = $view->new_display('block', 'User Constituency Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Weitere Kandidierende im Wahlkreis [field_user_constituency]';
  $handler->display->display_options['display_description'] = 'Show all other candidates in the same constituency';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = 'circular';
  $handler->display->display_options['style_options']['visible'] = '';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Exluded | User Constituency */
  $handler->display->display_options['fields']['field_user_constituency']['id'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['field'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['ui_name'] = 'Exluded | User Constituency';
  $handler->display->display_options['fields']['field_user_constituency']['label'] = '';
  $handler->display->display_options['fields']['field_user_constituency']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_constituency']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_constituency']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_constituency']['delta_offset'] = '0';
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: Profile Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['ui_name'] = 'Benutzer: Profile Picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_picture']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['alter']['alt'] = 'zum vollständigen Profil';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_picture']['element_wrapper_class'] = 'float-left push-right-s';
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'file_view_mode' => 'pw_file_portrait_xs',
  );
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['label'] = 'user data';
  $handler->display->display_options['fields']['fieldset']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'fieldset_1',
    1 => 'fieldset_2',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'small';
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['label'] = 'name and party';
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
    0 => 'field_user_fname',
    1 => 'field_user_lname',
    2 => 'field_user_party',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['type'] = 'div';
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: Party */
  $handler->display->display_options['fields']['field_user_party']['id'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['fields']['field_user_party']['field'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['label'] = '';
  $handler->display->display_options['fields']['field_user_party']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_party']['alter']['text'] = '[field_user_fname] [field_user_lname], [field_user_party]';
  $handler->display->display_options['fields']['field_user_party']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_party']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_user_party']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_party']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party']['delta_offset'] = '0';
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_2']['id'] = 'fieldset_2';
  $handler->display->display_options['fields']['fieldset_2']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_2']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_2']['label'] = 'dialogue';
  $handler->display->display_options['fields']['fieldset_2']['children'] = array(
    0 => 'field_user_questions_get',
    1 => 'field_user_answers_give',
  );
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['classes'] = 'medium';
  /* Feld: Benutzer: Questions Get */
  $handler->display->display_options['fields']['field_user_questions_get']['id'] = 'field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['table'] = 'field_data_field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['field'] = 'field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['label'] = '';
  $handler->display->display_options['fields']['field_user_questions_get']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_questions_get']['alter']['text'] = '[field_user_questions_get] / ';
  $handler->display->display_options['fields']['field_user_questions_get']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_questions_get']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Benutzer: Answers Give */
  $handler->display->display_options['fields']['field_user_answers_give']['id'] = 'field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['table'] = 'field_data_field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['field'] = 'field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['label'] = '';
  $handler->display->display_options['fields']['field_user_answers_give']['alter']['text'] = '[field_user_answers_give] Answers';
  $handler->display->display_options['fields']['field_user_answers_give']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_answers_give']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$profiluser = $myuser = user_load($row->uid);
$profiluserroles = $profiluser->roles;
if(in_array("Premium User",$profiluserroles)) {
print theme(\'image_style\', array(\'path\' => $data->field_field_user_picture[0][\'raw\'][\'uri\'], \'style_name\' => \'pw_portrait_m\'));
}
$user = menu_get_object(\'user\');
';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sortierkriterien: Benutzer: Answers Give (field_user_answers_give) */
  $handler->display->display_options['sorts']['field_user_answers_give_value']['id'] = 'field_user_answers_give_value';
  $handler->display->display_options['sorts']['field_user_answers_give_value']['table'] = 'field_data_field_user_answers_give';
  $handler->display->display_options['sorts']['field_user_answers_give_value']['field'] = 'field_user_answers_give_value';
  $handler->display->display_options['sorts']['field_user_answers_give_value']['order'] = 'DESC';
  /* Sortierkriterien: Benutzer: Questions Get (field_user_questions_get) */
  $handler->display->display_options['sorts']['field_user_questions_get_value']['id'] = 'field_user_questions_get_value';
  $handler->display->display_options['sorts']['field_user_questions_get_value']['table'] = 'field_data_field_user_questions_get';
  $handler->display->display_options['sorts']['field_user_questions_get_value']['field'] = 'field_user_questions_get_value';
  $handler->display->display_options['sorts']['field_user_questions_get_value']['order'] = 'DESC';
  /* Sortierkriterien: Global: Zufall */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Taxonomie-Begriff: Begriff-ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_user_constituency_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['code'] = '$user = menu_get_object(\'user\');

if(sizeOf($user->field_user_constituency[\'und\']) >1)
{
  return $user->field_user_constituency[\'und\'][1][\'tid\'];
}
else
{
   return $user->field_user_constituency[\'und\'][0][\'tid\'];
}
';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'constituency' => 'constituency',
  );
  /* Kontextfilter: Benutzer: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Benutzer: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $export['constituency_for_the_profile'] = $view;

  $view = new view();
  $view->name = 'politicians';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Politicians';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Politicians Overview';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Politiker pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '5, 10, 20, 50, 100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle anzeigen -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'mail' => 'mail',
    'field_user_party' => 'field_user_party',
    'field_user_parliament' => 'field_user_parliament',
    'field_user_constituency' => 'field_user_constituency',
    'field_user_commitee' => 'field_user_commitee',
    'field_user_questions_get' => 'field_user_questions_get',
    'field_user_answers_give' => 'field_user_answers_give',
    'field_user_address_locality' => 'field_user_address_locality',
    'rid' => 'rid',
    'field_user_list_position' => 'field_user_list_position',
    'edit_node' => 'edit_node',
    'field_user_fname' => 'field_user_fname',
    'field_user_lname' => 'field_user_lname',
  );
  $handler->display->display_options['style_options']['default'] = 'field_user_list_position';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_party' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_parliament' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_constituency' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_commitee' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_questions_get' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_answers_give' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_address_locality' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_list_position' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_fname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_lname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Feld: Stapelverarbeitungen: Benutzer */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::user_block_user_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_user_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::1399' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pw_login_once_send_mail_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Feld: Benutzer: E-Mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Feld: Benutzer: Party */
  $handler->display->display_options['fields']['field_user_party']['id'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['fields']['field_user_party']['field'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['delta_offset'] = '0';
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_user_parliament']['id'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['table'] = 'field_data_field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['field'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['delta_offset'] = '0';
  /* Feld: Benutzer: Constituency */
  $handler->display->display_options['fields']['field_user_constituency']['id'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['field'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['delta_offset'] = '0';
  /* Feld: Benutzer: Committee */
  $handler->display->display_options['fields']['field_user_commitee']['id'] = 'field_user_commitee';
  $handler->display->display_options['fields']['field_user_commitee']['table'] = 'field_data_field_user_commitee';
  $handler->display->display_options['fields']['field_user_commitee']['field'] = 'field_user_commitee';
  $handler->display->display_options['fields']['field_user_commitee']['delta_offset'] = '0';
  /* Feld: Benutzer: Questions Get */
  $handler->display->display_options['fields']['field_user_questions_get']['id'] = 'field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['table'] = 'field_data_field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['field'] = 'field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['label'] = 'Fragen';
  $handler->display->display_options['fields']['field_user_questions_get']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Benutzer: Answers Give */
  $handler->display->display_options['fields']['field_user_answers_give']['id'] = 'field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['table'] = 'field_data_field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['field'] = 'field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['label'] = 'Antworten';
  $handler->display->display_options['fields']['field_user_answers_give']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Benutzer: Address - Ort (z.B. Stadt) */
  $handler->display->display_options['fields']['field_user_address_locality']['id'] = 'field_user_address_locality';
  $handler->display->display_options['fields']['field_user_address_locality']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['fields']['field_user_address_locality']['field'] = 'field_user_address_locality';
  $handler->display->display_options['fields']['field_user_address_locality']['label'] = 'Ort';
  /* Feld: Benutzer: Rollen */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Feld: Benutzer: List Position */
  $handler->display->display_options['fields']['field_user_list_position']['id'] = 'field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['table'] = 'field_data_field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['field'] = 'field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['label'] = 'Listenplatz';
  /* Feld: Benutzer: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['label'] = 'hidden';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'hidden';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  /* Sortierkriterien: Benutzer: Erstellungsdatum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filterkriterium: Benutzer: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Benutzer: First Name (field_user_fname) */
  $handler->display->display_options['filters']['field_user_fname_value']['id'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['field'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_fname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['operator_id'] = 'field_user_fname_value_op';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['label'] = 'Vorname';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['description'] = 'Suche nach Vornamen.';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['operator'] = 'field_user_fname_value_op';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['identifier'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_field'] = 'field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_dependent'] = 0;
  /* Filterkriterium: Benutzer: Last name (field_user_lname) */
  $handler->display->display_options['filters']['field_user_lname_value']['id'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_value']['field'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_lname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator_id'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['label'] = 'Nachname';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['description'] = 'Suche nach Nachnamen.';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['identifier'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_field'] = 'field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_dependent'] = 0;
  /* Filterkriterium: Benutzer: Rollen */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    181527986 => '181527986',
  );
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = TRUE;
  /* Filterkriterium: Benutzer: E-Mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-Mail';
  $handler->display->display_options['filters']['mail']['expose']['description'] = 'Suche nach E-Mail-Adressen.';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_field'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_dependent'] = 0;
  /* Filterkriterium: Benutzer: Party (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_party_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator_id'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['label'] = 'Partei';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['description'] = 'Suche nach Parteien.';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['identifier'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_party_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_party_tid']['vocabulary'] = 'party';
  /* Filterkriterium: Feld: Parliament (field_user_parliament) */
  $handler->display->display_options['filters']['field_user_parliament_tid']['id'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['table'] = 'field_data_field_user_parliament';
  $handler->display->display_options['filters']['field_user_parliament_tid']['field'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_parliament_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['operator_id'] = 'field_user_parliament_tid_op';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['label'] = 'Parlament';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['description'] = 'Suche nach Parlamenten.';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['operator'] = 'field_user_parliament_tid_op';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['identifier'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_parliament_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_parliament_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_parliament_tid']['vocabulary'] = 'parliaments';
  /* Filterkriterium: Benutzer: Constituency (field_user_constituency) */
  $handler->display->display_options['filters']['field_user_constituency_tid']['id'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['filters']['field_user_constituency_tid']['field'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_constituency_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator_id'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['label'] = 'Wahlkreis';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['description'] = 'Suche nach Wahlkreisen.';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['identifier'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_constituency_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_constituency_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_constituency_tid']['vocabulary'] = 'constituency';
  /* Filterkriterium: Benutzer: Committee (field_user_commitee) */
  $handler->display->display_options['filters']['field_user_commitee_tid']['id'] = 'field_user_commitee_tid';
  $handler->display->display_options['filters']['field_user_commitee_tid']['table'] = 'field_data_field_user_commitee';
  $handler->display->display_options['filters']['field_user_commitee_tid']['field'] = 'field_user_commitee_tid';
  $handler->display->display_options['filters']['field_user_commitee_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_commitee_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_commitee_tid']['expose']['operator_id'] = 'field_user_commitee_tid_op';
  $handler->display->display_options['filters']['field_user_commitee_tid']['expose']['label'] = 'Ausschuss';
  $handler->display->display_options['filters']['field_user_commitee_tid']['expose']['description'] = 'Suche nach Ausschüssen.';
  $handler->display->display_options['filters']['field_user_commitee_tid']['expose']['operator'] = 'field_user_commitee_tid_op';
  $handler->display->display_options['filters']['field_user_commitee_tid']['expose']['identifier'] = 'field_user_commitee_tid';
  $handler->display->display_options['filters']['field_user_commitee_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_commitee_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_commitee_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_commitee_tid']['vocabulary'] = 'committee';
  /* Filterkriterium: Benutzer: Address - Ort (z.B. Stadt) */
  $handler->display->display_options['filters']['field_user_address_locality']['id'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['filters']['field_user_address_locality']['field'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['operator_id'] = 'field_user_address_locality_op';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['label'] = 'Wohnort';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['description'] = 'Suche nach Wohnorten.';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['operator'] = 'field_user_address_locality_op';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['identifier'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_field'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_dependent'] = 0;
  /* Filterkriterium: Benutzer: Dynamic Field Politicians View */
  $handler->display->display_options['filters']['dynamic-field']['id'] = 'dynamic-field';
  $handler->display->display_options['filters']['dynamic-field']['table'] = 'users';
  $handler->display->display_options['filters']['dynamic-field']['field'] = 'dynamic-field';
  $handler->display->display_options['filters']['dynamic-field']['ui_name'] = 'Benutzer: Dynamic Field Politicians View';
  $handler->display->display_options['filters']['dynamic-field']['expose']['operator_id'] = 'dynamic-field_op';
  $handler->display->display_options['filters']['dynamic-field']['expose']['label'] = 'Dynamic Fields';
  $handler->display->display_options['filters']['dynamic-field']['expose']['operator'] = 'dynamic-field_op';
  $handler->display->display_options['filters']['dynamic-field']['expose']['identifier'] = 'dynamic-field';
  $handler->display->display_options['filters']['dynamic-field']['filterable_fields'] = array(
    'name' => 'name',
    'mail' => 'mail',
    'field_user_party' => 'field_user_party',
    'field_user_parliament' => 'field_user_parliament',
    'field_user_constituency' => 'field_user_constituency',
    'field_user_commitee' => 'field_user_commitee',
    'field_user_questions_get' => 'field_user_questions_get',
    'field_user_answers_give' => 'field_user_answers_give',
    'field_user_address_locality' => 'field_user_address_locality',
    'rid' => 'rid',
    'field_user_list_position' => 'field_user_list_position',
    'views_bulk_operations' => 0,
    'edit_node' => 0,
  );
  $handler->display->display_options['filters']['dynamic-field']['defaults_filterable_fields'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'mail' => 'mail',
    'field_user_party' => 'field_user_party',
    'field_user_parliament' => 'field_user_parliament',
    'edit_node' => 'edit_node',
    'field_user_constituency' => 0,
    'field_user_commitee' => 0,
    'field_user_questions_get' => 0,
    'field_user_answers_give' => 0,
    'field_user_address_locality' => 0,
    'rid' => 0,
    'field_user_list_position' => 0,
  );
  /* Filterkriterium: Benutzer: Dynamic Field Politicians Edit */
  $handler->display->display_options['filters']['dynamic-field_1']['id'] = 'dynamic-field_1';
  $handler->display->display_options['filters']['dynamic-field_1']['table'] = 'users';
  $handler->display->display_options['filters']['dynamic-field_1']['field'] = 'dynamic-field';
  $handler->display->display_options['filters']['dynamic-field_1']['ui_name'] = 'Benutzer: Dynamic Field Politicians Edit';
  $handler->display->display_options['filters']['dynamic-field_1']['expose']['operator_id'] = 'dynamic-field_1_op';
  $handler->display->display_options['filters']['dynamic-field_1']['expose']['label'] = 'Dynamic Fields';
  $handler->display->display_options['filters']['dynamic-field_1']['expose']['operator'] = 'dynamic-field_1_op';
  $handler->display->display_options['filters']['dynamic-field_1']['expose']['identifier'] = 'dynamic-field_1';
  $handler->display->display_options['filters']['dynamic-field_1']['filterable_fields'] = array(
    'name' => 'name',
    'mail' => 'mail',
    'field_user_party' => 'field_user_party',
    'field_user_parliament' => 'field_user_parliament',
    'field_user_constituency' => 'field_user_constituency',
    'field_user_commitee' => 'field_user_commitee',
    'field_user_questions_get' => 'field_user_questions_get',
    'field_user_answers_give' => 'field_user_answers_give',
    'field_user_address_locality' => 'field_user_address_locality',
    'rid' => 'rid',
    'field_user_list_position' => 'field_user_list_position',
    'views_bulk_operations' => 0,
    'edit_node' => 0,
  );
  $handler->display->display_options['filters']['dynamic-field_1']['defaults_filterable_fields'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'mail' => 'mail',
    'field_user_party' => 'field_user_party',
    'field_user_parliament' => 'field_user_parliament',
    'edit_node' => 'edit_node',
    'field_user_constituency' => 0,
    'field_user_commitee' => 0,
    'field_user_questions_get' => 0,
    'field_user_answers_give' => 0,
    'field_user_address_locality' => 0,
    'rid' => 0,
    'field_user_list_position' => 0,
  );

  /* Display: Politicians Overview */
  $handler = $view->new_display('page', 'Politicians Overview', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'field_user_fname' => 'field_user_fname',
    'field_user_lname' => 'field_user_lname',
    'mail' => 'mail',
    'field_user_party' => 'field_user_party',
    'field_user_parliament' => 'field_user_parliament',
    'field_user_constituency' => 'field_user_constituency',
    'field_user_commitee' => 'field_user_commitee',
    'field_user_questions_get' => 'field_user_questions_get',
    'field_user_answers_give' => 'field_user_answers_give',
    'field_user_address_locality' => 'field_user_address_locality',
    'rid' => 'rid',
    'field_user_list_position' => 'field_user_list_position',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'field_user_list_position';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_fname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_lname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_party' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_parliament' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_constituency' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_commitee' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_questions_get' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_answers_give' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_user_address_locality' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_list_position' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Stapelverarbeitungen: Benutzer */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::user_block_user_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_user_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::1399' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pw_login_once_send_mail_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Politiker';
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['label'] = 'hidden';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'hidden';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  /* Feld: Benutzer: E-Mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Feld: Benutzer: Party */
  $handler->display->display_options['fields']['field_user_party']['id'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['fields']['field_user_party']['field'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['label'] = 'Partei';
  $handler->display->display_options['fields']['field_user_party']['delta_offset'] = '0';
  /* Feld: Feld: Parliament */
  $handler->display->display_options['fields']['field_user_parliament']['id'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['table'] = 'field_data_field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['field'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['label'] = 'Parlament';
  $handler->display->display_options['fields']['field_user_parliament']['delta_offset'] = '0';
  /* Feld: Benutzer: Constituency */
  $handler->display->display_options['fields']['field_user_constituency']['id'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['field'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['label'] = 'Wahlkreis';
  $handler->display->display_options['fields']['field_user_constituency']['delta_offset'] = '0';
  /* Feld: Benutzer: Committee */
  $handler->display->display_options['fields']['field_user_commitee']['id'] = 'field_user_commitee';
  $handler->display->display_options['fields']['field_user_commitee']['table'] = 'field_data_field_user_commitee';
  $handler->display->display_options['fields']['field_user_commitee']['field'] = 'field_user_commitee';
  $handler->display->display_options['fields']['field_user_commitee']['label'] = 'Ausschuss';
  $handler->display->display_options['fields']['field_user_commitee']['delta_offset'] = '0';
  /* Feld: Benutzer: Questions Get */
  $handler->display->display_options['fields']['field_user_questions_get']['id'] = 'field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['table'] = 'field_data_field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['field'] = 'field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get']['label'] = 'Fragen';
  $handler->display->display_options['fields']['field_user_questions_get']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Benutzer: Answers Give */
  $handler->display->display_options['fields']['field_user_answers_give']['id'] = 'field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['table'] = 'field_data_field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['field'] = 'field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give']['label'] = 'Antworten';
  $handler->display->display_options['fields']['field_user_answers_give']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Benutzer: Address - Ort (z.B. Stadt) */
  $handler->display->display_options['fields']['field_user_address_locality']['id'] = 'field_user_address_locality';
  $handler->display->display_options['fields']['field_user_address_locality']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['fields']['field_user_address_locality']['field'] = 'field_user_address_locality';
  $handler->display->display_options['fields']['field_user_address_locality']['label'] = 'Ort';
  /* Feld: Benutzer: Rollen */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Feld: Benutzer: List Position */
  $handler->display->display_options['fields']['field_user_list_position']['id'] = 'field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['table'] = 'field_data_field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['field'] = 'field_user_list_position';
  $handler->display->display_options['fields']['field_user_list_position']['label'] = 'Listenplatz';
  /* Feld: Benutzer: ‚Bearbeiten‘-Link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Benutzer: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterium: Benutzer: First Name (field_user_fname) */
  $handler->display->display_options['filters']['field_user_fname_value']['id'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['field'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_fname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['operator_id'] = 'field_user_fname_value_op';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['label'] = 'Vorname';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['description'] = 'Suche nach Vornamen.';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['operator'] = 'field_user_fname_value_op';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['identifier'] = 'field_user_fname_value';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_field'] = 'field_user_fname';
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_user_fname_value']['expose']['autocomplete_dependent'] = 0;
  /* Filterkriterium: Benutzer: Last name (field_user_lname) */
  $handler->display->display_options['filters']['field_user_lname_value']['id'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_value']['field'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_lname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator_id'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['label'] = 'Nachname';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['description'] = 'Suche nach Nachnamen.';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['operator'] = 'field_user_lname_value_op';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['identifier'] = 'field_user_lname_value';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_field'] = 'field_user_lname';
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_user_lname_value']['expose']['autocomplete_dependent'] = 0;
  /* Filterkriterium: Benutzer: Rollen */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    181527986 => '181527986',
  );
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = TRUE;
  /* Filterkriterium: Benutzer: E-Mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'contains';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-Mail';
  $handler->display->display_options['filters']['mail']['expose']['description'] = 'Suche nach E-Mail-Adressen.';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_field'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['mail']['expose']['autocomplete_dependent'] = 0;
  /* Filterkriterium: Benutzer: Party (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_data_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_party_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator_id'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['label'] = 'Partei';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['description'] = 'Suche nach Parteien.';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['identifier'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_party_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_party_tid']['vocabulary'] = 'party';
  /* Filterkriterium: Feld: Parliament (field_user_parliament) */
  $handler->display->display_options['filters']['field_user_parliament_tid']['id'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['table'] = 'field_data_field_user_parliament';
  $handler->display->display_options['filters']['field_user_parliament_tid']['field'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_parliament_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['operator_id'] = 'field_user_parliament_tid_op';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['label'] = 'Parlament';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['description'] = 'Suche nach Parlamenten.';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['operator'] = 'field_user_parliament_tid_op';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['identifier'] = 'field_user_parliament_tid';
  $handler->display->display_options['filters']['field_user_parliament_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_parliament_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_parliament_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_parliament_tid']['vocabulary'] = 'parliaments';
  /* Filterkriterium: Benutzer: Constituency (field_user_constituency) */
  $handler->display->display_options['filters']['field_user_constituency_tid']['id'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['filters']['field_user_constituency_tid']['field'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_constituency_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator_id'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['label'] = 'Wahlkreis';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['description'] = 'Suche nach Wahlkreisen.';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['identifier'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_constituency_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_constituency_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_constituency_tid']['vocabulary'] = 'constituency';
  /* Filterkriterium: Benutzer: Committee (field_user_commitee) */
  $handler->display->display_options['filters']['field_user_commitee_tid']['id'] = 'field_user_commitee_tid';
  $handler->display->display_options['filters']['field_user_commitee_tid']['table'] = 'field_data_field_user_commitee';
  $handler->display->display_options['filters']['field_user_commitee_tid']['field'] = 'field_user_commitee_tid';
  $handler->display->display_options['filters']['field_user_commitee_tid']['value'] = '';
  $handler->display->display_options['filters']['field_user_commitee_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_commitee_tid']['expose']['operator_id'] = 'field_user_commitee_tid_op';
  $handler->display->display_options['filters']['field_user_commitee_tid']['expose']['label'] = 'Ausschuss';
  $handler->display->display_options['filters']['field_user_commitee_tid']['expose']['description'] = 'Suche nach Ausschüssen.';
  $handler->display->display_options['filters']['field_user_commitee_tid']['expose']['operator'] = 'field_user_commitee_tid_op';
  $handler->display->display_options['filters']['field_user_commitee_tid']['expose']['identifier'] = 'field_user_commitee_tid';
  $handler->display->display_options['filters']['field_user_commitee_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_commitee_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_user_commitee_tid']['type'] = 'textfield';
  $handler->display->display_options['filters']['field_user_commitee_tid']['vocabulary'] = 'committee';
  /* Filterkriterium: Benutzer: Address - Ort (z.B. Stadt) */
  $handler->display->display_options['filters']['field_user_address_locality']['id'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['table'] = 'field_data_field_user_address';
  $handler->display->display_options['filters']['field_user_address_locality']['field'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['operator_id'] = 'field_user_address_locality_op';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['label'] = 'Wohnort';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['description'] = 'Suche nach Wohnorten.';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['operator'] = 'field_user_address_locality_op';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['identifier'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_filter'] = 1;
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_field'] = 'field_user_address_locality';
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['field_user_address_locality']['expose']['autocomplete_dependent'] = 0;
  /* Filterkriterium: Benutzer: Dynamic Field Politicians View */
  $handler->display->display_options['filters']['dynamic-field']['id'] = 'dynamic-field';
  $handler->display->display_options['filters']['dynamic-field']['table'] = 'users';
  $handler->display->display_options['filters']['dynamic-field']['field'] = 'dynamic-field';
  $handler->display->display_options['filters']['dynamic-field']['ui_name'] = 'Benutzer: Dynamic Field Politicians View';
  $handler->display->display_options['filters']['dynamic-field']['exposed'] = TRUE;
  $handler->display->display_options['filters']['dynamic-field']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['dynamic-field']['expose']['label'] = 'Felder auswählen';
  $handler->display->display_options['filters']['dynamic-field']['expose']['operator'] = 'dynamic-field_op';
  $handler->display->display_options['filters']['dynamic-field']['expose']['identifier'] = 'dynamic-field-view';
  $handler->display->display_options['filters']['dynamic-field']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['dynamic-field']['filterable_fields'] = array(
    'name' => 'name',
    'mail' => 'mail',
    'field_user_party' => 'field_user_party',
    'field_user_parliament' => 'field_user_parliament',
    'field_user_constituency' => 'field_user_constituency',
    'field_user_commitee' => 'field_user_commitee',
    'field_user_questions_get' => 'field_user_questions_get',
    'field_user_answers_give' => 'field_user_answers_give',
    'field_user_address_locality' => 'field_user_address_locality',
    'rid' => 'rid',
    'field_user_list_position' => 'field_user_list_position',
    'views_bulk_operations' => 0,
    'edit_node' => 0,
  );
  $handler->display->display_options['filters']['dynamic-field']['defaults_filterable_fields'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'mail' => 'mail',
    'field_user_party' => 'field_user_party',
    'field_user_parliament' => 'field_user_parliament',
    'edit_node' => 'edit_node',
    'field_user_constituency' => 0,
    'field_user_commitee' => 0,
    'field_user_questions_get' => 0,
    'field_user_answers_give' => 0,
    'field_user_address_locality' => 0,
    'rid' => 0,
    'field_user_list_position' => 0,
  );
  $handler->display->display_options['path'] = 'admin/people/politicians';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Politicians';
  $handler->display->display_options['menu']['name'] = 'management';

  /* Display: Politicians Bulk Edit */
  $handler = $view->new_display('page_with_page_title', 'Politicians Bulk Edit', 'page_with_page_title_1');
  $export['politicians'] = $view;

  $view = new view();
  $view->name = 'polls_profile';
  $view->description = '';
  $view->tag = 'profile, poll';
  $view->base_table = 'node';
  $view->human_name = 'PW Polls for the profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'weiterlesen';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_pw_poll_date' => 'field_pw_poll_date',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pw_poll_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  /* Kopfbereich: Global: Textbereich */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Beziehung: Inhalt: Votes */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['label'] = 'Stimmen';
  $handler->display->display_options['relationships']['votingapi_vote']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
  );
  $handler->display->display_options['relationships']['votingapi_vote']['current_user'] = 0;
  /* Beziehung: Stimmen: Benutzer */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'votingapi_vote';
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname']['element_default_classes'] = FALSE;
  /* Feld: Inhalt: Date */
  $handler->display->display_options['fields']['field_pw_poll_date']['id'] = 'field_pw_poll_date';
  $handler->display->display_options['fields']['field_pw_poll_date']['table'] = 'field_data_field_pw_poll_date';
  $handler->display->display_options['fields']['field_pw_poll_date']['field'] = 'field_pw_poll_date';
  $handler->display->display_options['fields']['field_pw_poll_date']['label'] = '';
  $handler->display->display_options['fields']['field_pw_poll_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pw_poll_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pw_poll_date']['element_wrapper_class'] = 'date';
  $handler->display->display_options['fields']['field_pw_poll_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pw_poll_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'title';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  /* Feld: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['php']['element_wrapper_class'] = 'poll-behavior';
  $handler->display->display_options['fields']['php']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php

$uid = arg(2);

$nid = $row->nid;
$sql = "SELECT entity_id, value FROM {votingapi_vote} WHERE entity_id=:nid AND uid=:uid";
$result  = db_query($sql,array(\':nid\'=>$nid,\':uid\'=>$uid));
$record = $result->fetchObject();

if($record->value == 0){
 echo t(\'yes\');
}else if($record->value == 1){
 echo t(\'no\');
}else if($record->value == 2){
 echo t(\'absent\');
}else{
 echo t(\'blank\');
}

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  /* Sortierkriterien: Inhalt: Date (field_pw_poll_date) */
  $handler->display->display_options['sorts']['field_pw_poll_date_value']['id'] = 'field_pw_poll_date_value';
  $handler->display->display_options['sorts']['field_pw_poll_date_value']['table'] = 'field_data_field_pw_poll_date';
  $handler->display->display_options['sorts']['field_pw_poll_date_value']['field'] = 'field_pw_poll_date_value';
  $handler->display->display_options['sorts']['field_pw_poll_date_value']['order'] = 'DESC';
  /* Kontextfilter: Stimmen: Benutzer */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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
    'pw_poll' => 'pw_poll',
  );

  /* Display: Last */
  $handler = $view->new_display('block', 'Last', 'last');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'content-wrapper';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  $handler->display->display_options['fields']['title_1']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title_1']['node_in_colorbox_height'] = '600';
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'uid';
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
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Voting behavior of [field_user_fname] [field_user_lname]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Info';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Deputies can challenge the Ceann Comhairle and demand a recorded vote by shouting Votáil! (Vote!) The Ceann Comhairle then shouts \'Votáil\' again which starts the voting process. We select the most important votes and document them. If you think an important vote is missing, then <a href="/en-gb/about/contact">please let us know</a>.';
  $handler->display->display_options['fields']['nothing_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'info-content element-hidden';
  $handler->display->display_options['fields']['nothing_1']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['nothing_1']['element_label_class'] = 'info-title';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'ic-info';
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Feld: Global PHP: Overview Chart */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['ui_name'] = 'Global PHP: Overview Chart';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['text'] = '[php_1]
<div class="poll-behavior"><span class="icon yes"></span>yes</div>
<div class="poll-behavior"><span class="icon no"></span>no</div>
<div class="poll-behavior"><span class="icon absent"></span>absent</div>
<div class="poll-behavior"><span class="icon blank"></span>blank</div>

';
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['php_1']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['alt'] = '[title_1]';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['php_1']['element_wrapper_class'] = 'float-left';
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
print pw_blocks_get_chart($row->nid,\'total\', NULL, 105,128);
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  /* Feld: Inhalt: Date */
  $handler->display->display_options['fields']['field_pw_poll_date']['id'] = 'field_pw_poll_date';
  $handler->display->display_options['fields']['field_pw_poll_date']['table'] = 'field_data_field_pw_poll_date';
  $handler->display->display_options['fields']['field_pw_poll_date']['field'] = 'field_pw_poll_date';
  $handler->display->display_options['fields']['field_pw_poll_date']['label'] = '';
  $handler->display->display_options['fields']['field_pw_poll_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pw_poll_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pw_poll_date']['element_wrapper_class'] = 'push-bottom-s';
  $handler->display->display_options['fields']['field_pw_poll_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pw_poll_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Global PHP: User Vote */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['ui_name'] = 'Global PHP: User Vote';
  $handler->display->display_options['fields']['php_2']['label'] = '';
  $handler->display->display_options['fields']['php_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['php_2']['alter']['text'] = '[field_user_fname] [field_user_lname] voted with <span class="inline [php_2]">[php_2]</span>';
  $handler->display->display_options['fields']['php_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_2']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['php_2']['element_wrapper_class'] = 'poll-behavior push-bottom-s';
  $handler->display->display_options['fields']['php_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
if(arg(1) == \'user\'){
$uid = arg(2);
}else{
$uid = arg(1);
}
$nid = $row->nid;
$sql = "SELECT entity_id, value FROM {votingapi_vote} WHERE entity_id=:nid AND uid=:uid";
$result  = db_query($sql,array(\':nid\'=>$nid,\':uid\'=>$uid));
$record = $result->fetchObject();

if($record->value == 0){
 echo t(\'yes\');
}else if($record->value == 1){
 echo t(\'no\');
}else if($record->value == 2){
 echo t(\'absent\');
}else{
 echo t(\'blank\');
}

?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Feld: Inhalt: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '155';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['body']['element_wrapper_class'] = 'description';
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '155',
  );
  /* Feld: Inhalt: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'link-poll';
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Details to vote';
  $handler->display->display_options['fields']['view_node']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['view_node']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['block_description'] = 'Poll profile: Last poll';

  /* Display: Archive */
  $handler = $view->new_display('block', 'Archive', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: Global: Textbereich */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Voting Archive of [field_user_fname] [field_user_lname] <a href="/print/polls/archive/[uid]" class="ic-print external" title="print voting archive">print</a></h3>';
  $handler->display->display_options['header']['area']['format'] = 'managed_content';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname']['element_default_classes'] = FALSE;
  /* Feld: Inhalt: Date */
  $handler->display->display_options['fields']['field_pw_poll_date']['id'] = 'field_pw_poll_date';
  $handler->display->display_options['fields']['field_pw_poll_date']['table'] = 'field_data_field_pw_poll_date';
  $handler->display->display_options['fields']['field_pw_poll_date']['field'] = 'field_pw_poll_date';
  $handler->display->display_options['fields']['field_pw_poll_date']['label'] = '';
  $handler->display->display_options['fields']['field_pw_poll_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pw_poll_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pw_poll_date']['element_wrapper_class'] = 'date';
  $handler->display->display_options['fields']['field_pw_poll_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pw_poll_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'title';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  /* Feld: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['text'] = '<span class="poll-behavior"><span class="block [php]">[php]</span></span>';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if(arg(1) == \'user\'){
$uid = arg(2);
}else{
$uid = arg(1);
}
$nid = $row->nid;
$sql = "SELECT entity_id, value FROM {votingapi_vote} WHERE entity_id=:nid AND uid=:uid";
$result  = db_query($sql,array(\':nid\'=>$nid,\':uid\'=>$uid));
$record = $result->fetchObject();

if($record->value == 0){
 echo t(\'yes\');
}else if($record->value == 1){
 echo t(\'no\');
}else if($record->value == 2){
 echo t(\'absent\');
}else{
 echo t(\'blank\');
}

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
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
  $handler->display->display_options['block_description'] = 'Poll profile: Archive';

  /* Display: Print Page */
  $handler = $view->new_display('page', 'Print Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname']['element_default_classes'] = FALSE;
  /* Feld: Inhalt: Date */
  $handler->display->display_options['fields']['field_pw_poll_date']['id'] = 'field_pw_poll_date';
  $handler->display->display_options['fields']['field_pw_poll_date']['table'] = 'field_data_field_pw_poll_date';
  $handler->display->display_options['fields']['field_pw_poll_date']['field'] = 'field_pw_poll_date';
  $handler->display->display_options['fields']['field_pw_poll_date']['label'] = '';
  $handler->display->display_options['fields']['field_pw_poll_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pw_poll_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_pw_poll_date']['element_wrapper_class'] = 'date';
  $handler->display->display_options['fields']['field_pw_poll_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_pw_poll_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Feld: Inhalt: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'title';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['title']['node_in_colorbox_height'] = '600';
  /* Feld: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['text'] = '<span class="poll-behavior"><span class="block [php]">[php]</span></span>';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php

$uid = arg(2);

$nid = $row->nid;
$sql = "SELECT entity_id, value FROM {votingapi_vote} WHERE entity_id=:nid AND uid=:uid";
$result  = db_query($sql,array(\':nid\'=>$nid,\':uid\'=>$uid));
$record = $result->fetchObject();

if($record->value == 0){
 echo t(\'yes\');
}else if($record->value == 1){
 echo t(\'no\');
}else if($record->value == 2){
 echo t(\'absent\');
}else{
 echo t(\'blank\');
}

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Feld: Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['node_in_colorbox_width'] = '600';
  $handler->display->display_options['fields']['nid']['node_in_colorbox_height'] = '600';
  $handler->display->display_options['path'] = 'polls/archive/%';
  $export['polls_profile'] = $view;

  $view = new view();
  $view->name = 'profile_list_rev';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'user_revision';
  $view->human_name = 'PW Profile List Rev';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '%1 2014';
  $handler->display->display_options['css_class'] = 'pager-full';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'weiterlesen';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Erweiterte Optionen',
    ),
    'field_user_first_letter_lname_value' => array(
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
    'field_user_constituency_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
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
    'field_user_address_administrative_area' => array(
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
    'field_user_party_tid' => array(
      'bef_format' => 'bef',
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
    'field_user_qanda_ratio_value' => array(
      'bef_format' => 'bef_slider',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '100',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '<div class="ic-info"><div class="info-title"></div><div class="info-content element-hidden">Über den Schieber können Sie sich die Politikerinnen und Politiker auf dieser Seite entsprechend ihrer Antwortquote auf abgeordnetenwatch.de anzeigen lassen.</div></div>',
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
    'field_user_age_value' => array(
      'bef_format' => 'bef_slider',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '90',
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
    'field_user_gender_value' => array(
      'bef_format' => 'bef',
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
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'managed_content';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '21';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'zurück';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'clearfix';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'clearfix';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="pw-messages warning">
Mit Ihrer Auswahl wurden leider keine Ergebnisse gefunden.<br/>Bitte treffen Sie eine neue Auswahl über einen der angebotenen Filter.
</div>';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Beziehung: Feld (Historische Daten): Parliament (field_user_parliament) */
  $handler->display->display_options['relationships']['field_user_parliament_tid']['id'] = 'field_user_parliament_tid';
  $handler->display->display_options['relationships']['field_user_parliament_tid']['table'] = 'field_revision_field_user_parliament';
  $handler->display->display_options['relationships']['field_user_parliament_tid']['field'] = 'field_user_parliament_tid';
  $handler->display->display_options['relationships']['field_user_parliament_tid']['required'] = TRUE;
  /* Beziehung: User revision: Benutzer */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'user_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Beziehung: Benutzer (Historische Daten): Profile picture (field_user_picture:fid) */
  $handler->display->display_options['relationships']['field_user_picture_fid']['id'] = 'field_user_picture_fid';
  $handler->display->display_options['relationships']['field_user_picture_fid']['table'] = 'field_revision_field_user_picture';
  $handler->display->display_options['relationships']['field_user_picture_fid']['field'] = 'field_user_picture_fid';
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: User revision: Vid */
  $handler->display->display_options['fields']['vid_1']['id'] = 'vid_1';
  $handler->display->display_options['fields']['vid_1']['table'] = 'user_revision';
  $handler->display->display_options['fields']['vid_1']['field'] = 'vid';
  $handler->display->display_options['fields']['vid_1']['label'] = '';
  $handler->display->display_options['fields']['vid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid_1']['element_label_colon'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_user_picture-revision_id_1',
    1 => 'field_user_fname-revision_id_1',
    2 => 'field_user_lname-revision_id_1',
    3 => 'field_user_party-revision_id',
    4 => 'field_user_questions_get-revision_id',
    5 => 'field_user_answers_give-revision_id',
    6 => 'nothing_2',
    7 => 'fieldset_1',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'profiles-list-compact-wrapper';
  /* Feld: Benutzer (Historische Daten): Profile picture */
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['id'] = 'field_user_picture-revision_id_1';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['table'] = 'field_revision_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['field'] = 'field_user_picture-revision_id';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['alter']['text'] = '[field_user_picture-revision_id_1]';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['settings'] = array(
    'file_view_mode' => 'pw_file_portrait_m',
  );
  /* Feld: Excluded | User (historical data): First Name */
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['id'] = 'field_user_fname-revision_id_1';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['table'] = 'field_revision_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['field'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['ui_name'] = 'Excluded | User (historical data): First Name';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['alter']['text'] = '<strong>[field_user_fname-revision_id_1]';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['empty'] = '[field_user_fname]';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['hide_alter_empty'] = FALSE;
  /* Feld: Excluded | User (historical data): Last name */
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['id'] = 'field_user_lname-revision_id_1';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['table'] = 'field_revision_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['field'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['ui_name'] = 'Excluded | User (historical data): Last name';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['empty'] = '[field_user_lname]';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['hide_alter_empty'] = FALSE;
  /* Feld: Benutzer (Historische Daten): Party */
  $handler->display->display_options['fields']['field_user_party-revision_id']['id'] = 'field_user_party-revision_id';
  $handler->display->display_options['fields']['field_user_party-revision_id']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['fields']['field_user_party-revision_id']['field'] = 'field_user_party-revision_id';
  $handler->display->display_options['fields']['field_user_party-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_party-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_party-revision_id']['alter']['text'] = '[field_user_fname-revision_id_1] [field_user_lname-revision_id_1], [field_user_party-revision_id]';
  $handler->display->display_options['fields']['field_user_party-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_party-revision_id']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['field_user_party-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_party-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party-revision_id']['delta_offset'] = '0';
  /* Feld: Excluded | User (historical data): Questions Get */
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['id'] = 'field_user_questions_get-revision_id';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['table'] = 'field_revision_field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['field'] = 'field_user_questions_get-revision_id';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['ui_name'] = 'Excluded | User (historical data): Questions Get';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['alter']['text'] = '[field_user_questions_get-revision_id-value] Fragen';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Excluded | User (historical data): Answers Give */
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['id'] = 'field_user_answers_give-revision_id';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['table'] = 'field_revision_field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['field'] = 'field_user_answers_give-revision_id';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['ui_name'] = 'Excluded | User (historical data): Answers Give';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['alter']['text'] = '[field_user_answers_give-revision_id-value] Antworten';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['element_wrapper_class'] = 'row push-bottom-s';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Rewritten | Custom text: Questions, Answers */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Rewritten | Custom text: Questions, Answers';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[field_user_questions_get-revision_id], [field_user_answers_give-revision_id]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
    0 => 'field_user_picture-revision_id',
    1 => 'field_user_fname-revision_id',
    2 => 'field_user_lname-revision_id',
    3 => 'field_user_party-revision_id_1',
    4 => 'field_user_parliament-revision_id',
    5 => 'field_user_constituency-revision_id',
    6 => 'nothing',
    7 => 'nothing_1',
    8 => 'expression',
    9 => 'vid',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['classes'] = 'element-hidden profile-list-compact-info';
  /* Feld: Benutzer (Historische Daten): Profile picture */
  $handler->display->display_options['fields']['field_user_picture-revision_id']['id'] = 'field_user_picture-revision_id';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['table'] = 'field_revision_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['field'] = 'field_user_picture-revision_id';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['alter']['path'] = 'profile/[name]/archive/[vid_1]';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['element_wrapper_class'] = 'profile-image img-outline';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['settings'] = array(
    'image_style' => 'pw_portrait_l__normal',
    'image_link' => '',
  );
  /* Feld: Benutzer (Historische Daten): First Name */
  $handler->display->display_options['fields']['field_user_fname-revision_id']['id'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['table'] = 'field_revision_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['field'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['alter']['text'] = '<h3>[field_user_fname-revision_id]';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['empty'] = '<h3>[field_user_fname]';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['hide_alter_empty'] = FALSE;
  /* Feld: Benutzer (Historische Daten): Last name */
  $handler->display->display_options['fields']['field_user_lname-revision_id']['id'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['table'] = 'field_revision_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['field'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname-revision_id']['alter']['text'] = '[field_user_lname-revision_id]</h3>';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname-revision_id']['empty'] = '[field_user_lname]</h3>';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['hide_alter_empty'] = FALSE;
  /* Feld: Benutzer (Historische Daten): Party */
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['id'] = 'field_user_party-revision_id_1';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['field'] = 'field_user_party-revision_id';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['element_wrapper_class'] = 'row party push-bottom-xxs';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['delta_offset'] = '0';
  /* Feld: Feld (Historische Daten): Parliament */
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['id'] = 'field_user_parliament-revision_id';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['table'] = 'field_revision_field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['field'] = 'field_user_parliament-revision_id';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['element_wrapper_class'] = 'row';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['delta_offset'] = '0';
  /* Feld: Benutzer (Historische Daten): Constituency */
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['id'] = 'field_user_constituency-revision_id';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['table'] = 'field_revision_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['field'] = 'field_user_constituency-revision_id';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['element_wrapper_class'] = 'row';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['delta_offset'] = '0';
  /* Feld: Reused | Questions get */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Reused | Questions get';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_user_questions_get-revision_id]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'row';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Feld: Reused | Answers give */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Reused | Answers give';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_user_answers_give-revision_id]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'row push-bottom-s';
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Feld: Global: Math expression: Response rate */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['ui_name'] = 'Global: Math expression: Response rate';
  $handler->display->display_options['fields']['expression']['label'] = '';
  $handler->display->display_options['fields']['expression']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['expression']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['expression']['element_wrapper_class'] = 'row push-bottom-xs';
  $handler->display->display_options['fields']['expression']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['expression']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['expression']['precision'] = '1';
  $handler->display->display_options['fields']['expression']['decimal'] = ',';
  $handler->display->display_options['fields']['expression']['separator'] = '';
  $handler->display->display_options['fields']['expression']['suffix'] = '% Antwortquote';
  $handler->display->display_options['fields']['expression']['expression'] = '[field_user_answers_give-revision_id] / [field_user_questions_get-revision_id] ';
  /* Feld: Link to profile */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'user_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['ui_name'] = 'Link to profile';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['vid']['alter']['text'] = 'Profil besuchen';
  $handler->display->display_options['fields']['vid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['vid']['alter']['path'] = 'profile/[name]/archive/[vid_1]';
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['vid']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['vid']['element_wrapper_class'] = 'link-profile row bg-white';
  $handler->display->display_options['fields']['vid']['element_default_classes'] = FALSE;
  /* Sortierkriterien: Benutzer (Historische Daten): Answers Give (field_user_answers_give) */
  $handler->display->display_options['sorts']['field_user_answers_give_value_1']['id'] = 'field_user_answers_give_value_1';
  $handler->display->display_options['sorts']['field_user_answers_give_value_1']['table'] = 'field_revision_field_user_answers_give';
  $handler->display->display_options['sorts']['field_user_answers_give_value_1']['field'] = 'field_user_answers_give_value';
  $handler->display->display_options['sorts']['field_user_answers_give_value_1']['order'] = 'DESC';
  /* Sortierkriterien: Benutzer (Historische Daten): Questions Get (field_user_questions_get) */
  $handler->display->display_options['sorts']['field_user_questions_get_value']['id'] = 'field_user_questions_get_value';
  $handler->display->display_options['sorts']['field_user_questions_get_value']['table'] = 'field_revision_field_user_questions_get';
  $handler->display->display_options['sorts']['field_user_questions_get_value']['field'] = 'field_user_questions_get_value';
  $handler->display->display_options['sorts']['field_user_questions_get_value']['order'] = 'DESC';
  /* Sortierkriterien: Benutzer: Profile picture (field_user_picture:fid:null sort) */
  $handler->display->display_options['sorts']['field_user_picture_fid_nullsort']['id'] = 'field_user_picture_fid_nullsort';
  $handler->display->display_options['sorts']['field_user_picture_fid_nullsort']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['sorts']['field_user_picture_fid_nullsort']['field'] = 'field_user_picture_fid_nullsort';
  $handler->display->display_options['sorts']['field_user_picture_fid_nullsort']['relationship'] = 'uid';
  /* Sortierkriterien: Benutzer (Historische Daten): Last name (field_user_lname) */
  $handler->display->display_options['sorts']['field_user_lname_value']['id'] = 'field_user_lname_value';
  $handler->display->display_options['sorts']['field_user_lname_value']['table'] = 'field_revision_field_user_lname';
  $handler->display->display_options['sorts']['field_user_lname_value']['field'] = 'field_user_lname_value';
  /* Kontextfilter: Feld (Historische Daten): Parliament (field_user_parliament) */
  $handler->display->display_options['arguments']['field_user_parliament_tid']['id'] = 'field_user_parliament_tid';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['table'] = 'field_revision_field_user_parliament';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['field'] = 'field_user_parliament_tid';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_user_parliament_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_user_parliament_tid']['validate_options']['vocabularies'] = array(
    'parliaments' => 'parliaments',
  );
  $handler->display->display_options['arguments']['field_user_parliament_tid']['validate_options']['type'] = 'convert';
  /* Kontextfilter: Benutzer (Historische Daten): Roles (revisionable) (field_user_roles_for_view_mode_s) */
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['id'] = 'field_user_roles_for_view_mode_s_tid';
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['table'] = 'field_revision_field_user_roles_for_view_mode_s';
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['field'] = 'field_user_roles_for_view_mode_s_tid';
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['default_argument_options']['argument'] = 'Candidate';
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_user_roles_for_view_mode_s_tid']['validate_options']['code'] = 'if($handler->argument == \'deputies\'){
  $term_name = \'Deputy\';
}
else{
  $term_name = \'Candidate\';
}

$term_role = taxonomy_get_term_by_name($term_name, \'pw_profile_roles_for_view_mode_switch\');
if($term_role){
  $term_role_id = key($term_role);
  $handler->argument = $term_role_id;
  return TRUE;
}
return FALSE;';
  /* Filterkriterium: Benutzer: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Aktiv';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Filterkriterium: Benutzer (Historische Daten): First Letter of Lastname (field_user_first_letter_lname) */
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['id'] = 'field_user_first_letter_lname_value';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['table'] = 'field_revision_field_user_first_letter_lname';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['field'] = 'field_user_first_letter_lname_value';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['operator_id'] = 'field_user_first_letter_lname_value_op';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['label'] = 'user_first_letter_lname (field_user_first_letter_lname)';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['operator'] = 'field_user_first_letter_lname_value_op';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['identifier'] = 'field_user_first_letter_lname_value';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['label'] = 'Nach Namen filtern';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['identifier'] = 'field_user_first_letter_lname_value';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Alle',
      'operator' => 'not empty',
      'value' => '1',
    ),
    2 => array(
      'title' => 'A',
      'operator' => 'starts',
      'value' => 'A',
    ),
    3 => array(
      'title' => 'B',
      'operator' => 'starts',
      'value' => 'B',
    ),
    4 => array(
      'title' => 'C',
      'operator' => 'starts',
      'value' => 'C',
    ),
    5 => array(
      'title' => 'D',
      'operator' => 'starts',
      'value' => 'D',
    ),
    6 => array(
      'title' => 'E',
      'operator' => 'starts',
      'value' => 'E',
    ),
    7 => array(
      'title' => 'F',
      'operator' => 'starts',
      'value' => 'F',
    ),
    8 => array(
      'title' => 'G',
      'operator' => 'starts',
      'value' => 'G',
    ),
    9 => array(
      'title' => 'H',
      'operator' => 'starts',
      'value' => 'H',
    ),
    10 => array(
      'title' => 'I',
      'operator' => 'starts',
      'value' => 'I',
    ),
    11 => array(
      'title' => 'J',
      'operator' => 'starts',
      'value' => 'J',
    ),
    12 => array(
      'title' => 'K',
      'operator' => 'starts',
      'value' => 'K',
    ),
    13 => array(
      'title' => 'L',
      'operator' => 'starts',
      'value' => 'L',
    ),
    14 => array(
      'title' => 'M',
      'operator' => 'starts',
      'value' => 'M',
    ),
    15 => array(
      'title' => 'N',
      'operator' => 'starts',
      'value' => 'N',
    ),
    16 => array(
      'title' => 'O',
      'operator' => 'starts',
      'value' => 'O',
    ),
    17 => array(
      'title' => 'P',
      'operator' => 'starts',
      'value' => 'P',
    ),
    18 => array(
      'title' => 'Q',
      'operator' => '=',
      'value' => 'Q',
    ),
    19 => array(
      'title' => 'R',
      'operator' => '=',
      'value' => 'R',
    ),
    20 => array(
      'title' => 'S',
      'operator' => '=',
      'value' => 'S',
    ),
    21 => array(
      'title' => 'T',
      'operator' => '=',
      'value' => 'T',
    ),
    22 => array(
      'title' => 'U',
      'operator' => '=',
      'value' => 'U',
    ),
    23 => array(
      'title' => 'V',
      'operator' => '=',
      'value' => 'V',
    ),
    24 => array(
      'title' => 'W',
      'operator' => '=',
      'value' => 'W',
    ),
    25 => array(
      'title' => 'X',
      'operator' => '=',
      'value' => 'X',
    ),
    26 => array(
      'title' => 'Y',
      'operator' => '=',
      'value' => 'Y',
    ),
    27 => array(
      'title' => 'Z',
      'operator' => '=',
      'value' => 'Z',
    ),
  );
  /* Filterkriterium: Benutzer: Constituency (field_user_constituency) */
  $handler->display->display_options['filters']['field_user_constituency_tid']['id'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['filters']['field_user_constituency_tid']['field'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_constituency_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator_id'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['label'] = 'Bundesland wählen';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['identifier'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    181527986 => 0,
    51622513 => 0,
    185431326 => 0,
    140336230 => 0,
    237793809 => 0,
  );
  $handler->display->display_options['filters']['field_user_constituency_tid']['vocabulary'] = 'constituency';
  /* Filterkriterium: Benutzer (Historische Daten): Party (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_party_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator_id'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['label'] = 'Nach Partei filtern';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['identifier'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_party_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_party_tid']['vocabulary'] = 'party';
  /* Filterkriterium: Benutzer (Historische Daten): QuestionAnswerRatio (field_user_qanda_ratio) */
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['id'] = 'field_user_qanda_ratio_value';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['table'] = 'field_revision_field_user_qanda_ratio';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['field'] = 'field_user_qanda_ratio_value';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['value']['min'] = '0';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['value']['max'] = '100';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['operator_id'] = 'field_user_qanda_ratio_value_op';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['label'] = 'Antwortquote';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['operator'] = 'field_user_qanda_ratio_value_op';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['identifier'] = 'field_user_qanda_ratio_value';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  /* Filterkriterium: Benutzer (Historische Daten): Age (field_user_age) */
  $handler->display->display_options['filters']['field_user_age_value']['id'] = 'field_user_age_value';
  $handler->display->display_options['filters']['field_user_age_value']['table'] = 'field_revision_field_user_age';
  $handler->display->display_options['filters']['field_user_age_value']['field'] = 'field_user_age_value';
  $handler->display->display_options['filters']['field_user_age_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_user_age_value']['value']['min'] = '0';
  $handler->display->display_options['filters']['field_user_age_value']['value']['max'] = '90';
  $handler->display->display_options['filters']['field_user_age_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_age_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_age_value']['expose']['operator_id'] = 'field_user_age_value_op';
  $handler->display->display_options['filters']['field_user_age_value']['expose']['label'] = 'Alter';
  $handler->display->display_options['filters']['field_user_age_value']['expose']['operator'] = 'field_user_age_value_op';
  $handler->display->display_options['filters']['field_user_age_value']['expose']['identifier'] = 'field_user_age_value';
  $handler->display->display_options['filters']['field_user_age_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_age_value']['group_info']['label'] = 'Age (field_user_age)';
  $handler->display->display_options['filters']['field_user_age_value']['group_info']['identifier'] = 'field_user_age_value';
  $handler->display->display_options['filters']['field_user_age_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_user_age_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filterkriterium: Benutzer (Historische Daten): Gender (field_user_gender) */
  $handler->display->display_options['filters']['field_user_gender_value']['id'] = 'field_user_gender_value';
  $handler->display->display_options['filters']['field_user_gender_value']['table'] = 'field_revision_field_user_gender';
  $handler->display->display_options['filters']['field_user_gender_value']['field'] = 'field_user_gender_value';
  $handler->display->display_options['filters']['field_user_gender_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_gender_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['operator_id'] = 'field_user_gender_value_op';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['label'] = 'Geschlecht auswählen';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['operator'] = 'field_user_gender_value_op';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['identifier'] = 'field_user_gender_value';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    181527986 => 0,
    51622513 => 0,
    185431326 => 0,
    140336230 => 0,
    237793809 => 0,
  );
  /* Filterkriterium: Datum: Between Dates (user_revision) */
  $handler->display->display_options['filters']['between_date_filter']['id'] = 'between_date_filter';
  $handler->display->display_options['filters']['between_date_filter']['table'] = 'user_revision';
  $handler->display->display_options['filters']['between_date_filter']['field'] = 'between_date_filter';
  $handler->display->display_options['filters']['between_date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['between_date_filter']['expose']['operator_id'] = 'between_date_filter_op';
  $handler->display->display_options['filters']['between_date_filter']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['between_date_filter']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['between_date_filter']['expose']['operator'] = 'between_date_filter_op';
  $handler->display->display_options['filters']['between_date_filter']['expose']['identifier'] = 'between_date_filter';
  $handler->display->display_options['filters']['between_date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['between_date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['between_date_filter']['start_date_field'] = 'field_revision_field_user_valid.field_user_valid_value';
  $handler->display->display_options['filters']['between_date_filter']['end_date_field'] = 'field_revision_field_user_valid.field_user_valid_value2';

  /* Display: Übersicht der Abgeordneten */
  $handler = $view->new_display('page', 'Übersicht der Abgeordneten', 'grid');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '21';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'zurück';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: User revision: Vid */
  $handler->display->display_options['fields']['vid_1']['id'] = 'vid_1';
  $handler->display->display_options['fields']['vid_1']['table'] = 'user_revision';
  $handler->display->display_options['fields']['vid_1']['field'] = 'vid';
  $handler->display->display_options['fields']['vid_1']['label'] = '';
  $handler->display->display_options['fields']['vid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid_1']['element_label_colon'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'fieldset_2',
    1 => 'field_user_title-revision_id',
    2 => 'field_user_fname-revision_id_1',
    3 => 'field_user_lname-revision_id_1',
    4 => 'field_user_party-revision_id',
    5 => 'field_user_questions_get-revision_id_1',
    6 => 'field_user_answers_give-revision_id_1',
    7 => 'nothing_2',
    8 => 'fieldset_1',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'profiles-list-compact-wrapper clearfix';
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_2']['id'] = 'fieldset_2';
  $handler->display->display_options['fields']['fieldset_2']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_2']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['fieldset_2']['children'] = array(
    0 => 'field_user_picture-revision_id_1',
    1 => 'field_image_copyright',
  );
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['classes'] = 'profile-picture push-bottom-xs';
  /* Feld: Benutzer (Historische Daten): Profile picture */
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['id'] = 'field_user_picture-revision_id_1';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['table'] = 'field_revision_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['field'] = 'field_user_picture-revision_id';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['alter']['text'] = '[field_user_picture-revision_id_1]';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['element_wrapper_class'] = 'file-image';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['settings'] = array(
    'image_style' => 'pw_portrait_m',
    'image_link' => 'content',
  );
  /* Feld: Datei: copyright */
  $handler->display->display_options['fields']['field_image_copyright']['id'] = 'field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['table'] = 'field_data_field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['field'] = 'field_image_copyright';
  $handler->display->display_options['fields']['field_image_copyright']['relationship'] = 'field_user_picture_fid';
  $handler->display->display_options['fields']['field_image_copyright']['label'] = '';
  $handler->display->display_options['fields']['field_image_copyright']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_copyright']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_image_copyright']['element_wrapper_class'] = 'copyright push-bottom-xs';
  $handler->display->display_options['fields']['field_image_copyright']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image_copyright']['hide_empty'] = TRUE;
  /* Feld: Excluded | User (historical data): Title */
  $handler->display->display_options['fields']['field_user_title-revision_id']['id'] = 'field_user_title-revision_id';
  $handler->display->display_options['fields']['field_user_title-revision_id']['table'] = 'field_revision_field_user_title';
  $handler->display->display_options['fields']['field_user_title-revision_id']['field'] = 'field_user_title-revision_id';
  $handler->display->display_options['fields']['field_user_title-revision_id']['ui_name'] = 'Excluded | User (historical data): Title';
  $handler->display->display_options['fields']['field_user_title-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_title-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_title-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_title-revision_id']['element_default_classes'] = FALSE;
  /* Feld: Excluded | User (historical data): First Name */
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['id'] = 'field_user_fname-revision_id_1';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['table'] = 'field_revision_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['field'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['ui_name'] = 'Excluded | User (historical data): First Name';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['alter']['text'] = '[field_user_fname-revision_id_1]';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['empty'] = '[field_user_fname]';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['hide_alter_empty'] = FALSE;
  /* Feld: Excluded | User (historical data): Last name */
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['id'] = 'field_user_lname-revision_id_1';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['table'] = 'field_revision_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['field'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['ui_name'] = 'Excluded | User (historical data): Last name';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['empty'] = '[field_user_lname]';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['hide_alter_empty'] = FALSE;
  /* Feld: Benutzer (Historische Daten): Party */
  $handler->display->display_options['fields']['field_user_party-revision_id']['id'] = 'field_user_party-revision_id';
  $handler->display->display_options['fields']['field_user_party-revision_id']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['fields']['field_user_party-revision_id']['field'] = 'field_user_party-revision_id';
  $handler->display->display_options['fields']['field_user_party-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_party-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_party-revision_id']['alter']['text'] = '[field_user_title-revision_id] [field_user_fname-revision_id_1] [field_user_lname-revision_id_1], [field_user_party-revision_id]';
  $handler->display->display_options['fields']['field_user_party-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_party-revision_id']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['field_user_party-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_party-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party-revision_id']['delta_offset'] = '0';
  /* Feld: Benutzer (Historische Daten): Questions Get */
  $handler->display->display_options['fields']['field_user_questions_get-revision_id_1']['id'] = 'field_user_questions_get-revision_id_1';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id_1']['table'] = 'field_revision_field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id_1']['field'] = 'field_user_questions_get-revision_id';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_questions_get-revision_id_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_questions_get-revision_id_1']['alter']['text'] = '[field_user_questions_get-revision_id_1]';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_questions_get-revision_id_1']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Benutzer (Historische Daten): Answers Give */
  $handler->display->display_options['fields']['field_user_answers_give-revision_id_1']['id'] = 'field_user_answers_give-revision_id_1';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id_1']['table'] = 'field_revision_field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id_1']['field'] = 'field_user_answers_give-revision_id';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_answers_give-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_answers_give-revision_id_1']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Rewritten | Custom text: Questions, Answers */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Rewritten | Custom text: Questions, Answers';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[field_user_questions_get-revision_id_1], [field_user_answers_give-revision_id_1]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
    0 => 'field_user_picture-revision_id',
    1 => 'field_user_fname-revision_id',
    2 => 'field_user_lname-revision_id',
    3 => 'field_user_party-revision_id_1',
    4 => 'field_user_parliament-revision_id',
    5 => 'field_user_constituency-revision_id',
    6 => 'nothing',
    7 => 'nothing_1',
    8 => 'field_user_qanda_ratio-revision_id',
    9 => 'vid',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['classes'] = 'element-hidden profile-list-compact-info';
  /* Feld: Benutzer (Historische Daten): Profile picture */
  $handler->display->display_options['fields']['field_user_picture-revision_id']['id'] = 'field_user_picture-revision_id';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['table'] = 'field_revision_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['field'] = 'field_user_picture-revision_id';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['alter']['path'] = 'profile/[name]';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['element_wrapper_class'] = 'profile-image img-outline';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['settings'] = array(
    'image_style' => 'pw_portrait_l__normal',
    'image_link' => '',
  );
  /* Feld: Benutzer (Historische Daten): First Name */
  $handler->display->display_options['fields']['field_user_fname-revision_id']['id'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['table'] = 'field_revision_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['field'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['alter']['text'] = '<h3>[field_user_title-revision_id] [field_user_fname-revision_id]';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['empty'] = '<h3>[field_user_fname]';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['hide_alter_empty'] = FALSE;
  /* Feld: Benutzer (Historische Daten): Last name */
  $handler->display->display_options['fields']['field_user_lname-revision_id']['id'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['table'] = 'field_revision_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['field'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname-revision_id']['alter']['text'] = '[field_user_lname-revision_id]</h3>';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname-revision_id']['empty'] = '[field_user_lname]</h3>';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['hide_alter_empty'] = FALSE;
  /* Feld: Benutzer (Historische Daten): Party */
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['id'] = 'field_user_party-revision_id_1';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['field'] = 'field_user_party-revision_id';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['element_wrapper_class'] = 'row party push-bottom-xxs';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['delta_offset'] = '0';
  /* Feld: Feld (Historische Daten): Parliament */
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['id'] = 'field_user_parliament-revision_id';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['table'] = 'field_revision_field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['field'] = 'field_user_parliament-revision_id';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['element_wrapper_class'] = 'row';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['delta_offset'] = '0';
  /* Feld: Benutzer (Historische Daten): Constituency */
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['id'] = 'field_user_constituency-revision_id';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['table'] = 'field_revision_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['field'] = 'field_user_constituency-revision_id';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['element_wrapper_class'] = 'row';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['delta_offset'] = '0';
  /* Feld: Reused | Questions get */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Reused | Questions get';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_user_questions_get-revision_id_1]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'row';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Feld: Reused | Answers give */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Reused | Answers give';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_user_answers_give-revision_id_1]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'row push-bottom-s';
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Feld:  Response rate */
  $handler->display->display_options['fields']['field_user_qanda_ratio-revision_id']['id'] = 'field_user_qanda_ratio-revision_id';
  $handler->display->display_options['fields']['field_user_qanda_ratio-revision_id']['table'] = 'field_revision_field_user_qanda_ratio';
  $handler->display->display_options['fields']['field_user_qanda_ratio-revision_id']['field'] = 'field_user_qanda_ratio-revision_id';
  $handler->display->display_options['fields']['field_user_qanda_ratio-revision_id']['ui_name'] = ' Response rate';
  $handler->display->display_options['fields']['field_user_qanda_ratio-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_qanda_ratio-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_qanda_ratio-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_qanda_ratio-revision_id']['alter']['text'] = '[field_user_qanda_ratio-revision_id-value] % Antwortquote';
  $handler->display->display_options['fields']['field_user_qanda_ratio-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_qanda_ratio-revision_id']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_qanda_ratio-revision_id']['element_wrapper_class'] = 'row push-bottom-xs';
  $handler->display->display_options['fields']['field_user_qanda_ratio-revision_id']['element_default_classes'] = FALSE;
  /* Feld: Link to profile */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'user_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['ui_name'] = 'Link to profile';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['vid']['alter']['text'] = 'Profil besuchen';
  $handler->display->display_options['fields']['vid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['vid']['alter']['path'] = 'profile/[name]';
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['vid']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['vid']['element_wrapper_class'] = 'link-profile row bg-white';
  $handler->display->display_options['fields']['vid']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Benutzer: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Aktiv';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Filterkriterium: Benutzer (Historische Daten): First Letter of Lastname (field_user_first_letter_lname) */
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['id'] = 'field_user_first_letter_lname_value';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['table'] = 'field_revision_field_user_first_letter_lname';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['field'] = 'field_user_first_letter_lname_value';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['operator_id'] = 'field_user_first_letter_lname_value_op';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['label'] = 'user_first_letter_lname (field_user_first_letter_lname)';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['operator'] = 'field_user_first_letter_lname_value_op';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['identifier'] = 'field_user_first_letter_lname_value';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['label'] = 'Nach Namen filtern';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['identifier'] = 'field_user_first_letter_lname_value';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'A',
      'operator' => '=',
      'value' => 'A',
    ),
    2 => array(
      'title' => 'B',
      'operator' => '=',
      'value' => 'B',
    ),
    3 => array(
      'title' => 'C',
      'operator' => '=',
      'value' => 'C',
    ),
    4 => array(
      'title' => 'D',
      'operator' => '=',
      'value' => 'D',
    ),
    5 => array(
      'title' => 'E',
      'operator' => '=',
      'value' => 'E',
    ),
    6 => array(
      'title' => 'F',
      'operator' => '=',
      'value' => 'F',
    ),
    7 => array(
      'title' => 'G',
      'operator' => '=',
      'value' => 'G',
    ),
    8 => array(
      'title' => 'H',
      'operator' => '=',
      'value' => 'H',
    ),
    9 => array(
      'title' => 'I',
      'operator' => '=',
      'value' => 'I',
    ),
    10 => array(
      'title' => 'J',
      'operator' => '=',
      'value' => 'J',
    ),
    11 => array(
      'title' => 'K',
      'operator' => '=',
      'value' => 'K',
    ),
    12 => array(
      'title' => 'L',
      'operator' => '=',
      'value' => 'L',
    ),
    13 => array(
      'title' => 'M',
      'operator' => '=',
      'value' => 'M',
    ),
    14 => array(
      'title' => 'N',
      'operator' => '=',
      'value' => 'N',
    ),
    15 => array(
      'title' => 'O',
      'operator' => '=',
      'value' => 'O',
    ),
    16 => array(
      'title' => 'P',
      'operator' => '=',
      'value' => 'P',
    ),
    17 => array(
      'title' => 'Q',
      'operator' => '=',
      'value' => 'Q',
    ),
    18 => array(
      'title' => 'R',
      'operator' => '=',
      'value' => 'R',
    ),
    19 => array(
      'title' => 'S',
      'operator' => '=',
      'value' => 'S',
    ),
    20 => array(
      'title' => 'T',
      'operator' => '=',
      'value' => 'T',
    ),
    21 => array(
      'title' => 'U',
      'operator' => '=',
      'value' => 'U',
    ),
    22 => array(
      'title' => 'V',
      'operator' => '=',
      'value' => 'V',
    ),
    23 => array(
      'title' => 'W',
      'operator' => '=',
      'value' => 'W',
    ),
    24 => array(
      'title' => 'X',
      'operator' => '=',
      'value' => 'X',
    ),
    25 => array(
      'title' => 'Y',
      'operator' => '=',
      'value' => 'Y',
    ),
    26 => array(
      'title' => 'Z',
      'operator' => '=',
      'value' => 'Z',
    ),
  );
  /* Filterkriterium: Benutzer (Historische Daten): Address (field_user_address:administrative_area) */
  $handler->display->display_options['filters']['field_user_address_administrative_area']['id'] = 'field_user_address_administrative_area';
  $handler->display->display_options['filters']['field_user_address_administrative_area']['table'] = 'field_revision_field_user_address';
  $handler->display->display_options['filters']['field_user_address_administrative_area']['field'] = 'field_user_address_administrative_area';
  $handler->display->display_options['filters']['field_user_address_administrative_area']['group'] = 1;
  $handler->display->display_options['filters']['field_user_address_administrative_area']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_address_administrative_area']['expose']['operator_id'] = 'field_user_address_administrative_area_op';
  $handler->display->display_options['filters']['field_user_address_administrative_area']['expose']['label'] = 'Bundesland';
  $handler->display->display_options['filters']['field_user_address_administrative_area']['expose']['operator'] = 'field_user_address_administrative_area_op';
  $handler->display->display_options['filters']['field_user_address_administrative_area']['expose']['identifier'] = 'field_user_address_administrative_area';
  $handler->display->display_options['filters']['field_user_address_administrative_area']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_address_administrative_area']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_user_address_administrative_area']['group_info']['label'] = 'Bundesland auswählen';
  $handler->display->display_options['filters']['field_user_address_administrative_area']['group_info']['identifier'] = 'field_user_address_administrative_area';
  $handler->display->display_options['filters']['field_user_address_administrative_area']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Bayern',
      'operator' => '=',
      'value' => 'BY',
    ),
    2 => array(
      'title' => 'Baden-Württemberg',
      'operator' => '=',
      'value' => 'BW',
    ),
    3 => array(
      'title' => 'Berlin',
      'operator' => '=',
      'value' => 'BE',
    ),
    4 => array(
      'title' => 'Brandenburg',
      'operator' => '=',
      'value' => 'BB',
    ),
    5 => array(
      'title' => 'Bremen',
      'operator' => '=',
      'value' => 'HB',
    ),
    6 => array(
      'title' => 'Hamburg',
      'operator' => '=',
      'value' => 'HH',
    ),
    7 => array(
      'title' => 'Hessen',
      'operator' => '=',
      'value' => 'HE',
    ),
    8 => array(
      'title' => 'Mecklenburg-Vorpommern',
      'operator' => '=',
      'value' => 'MV',
    ),
    9 => array(
      'title' => 'Niedersachsen',
      'operator' => '=',
      'value' => 'NI',
    ),
    10 => array(
      'title' => 'Nordrhein-Westfalen',
      'operator' => '=',
      'value' => 'NW',
    ),
    11 => array(
      'title' => 'Rheinland-Pfalz',
      'operator' => '=',
      'value' => 'RP',
    ),
    12 => array(
      'title' => 'Saarland',
      'operator' => '=',
      'value' => 'SL',
    ),
    13 => array(
      'title' => 'Sachsen',
      'operator' => '=',
      'value' => 'SN',
    ),
    14 => array(
      'title' => 'Sachsen-Anhalt',
      'operator' => '=',
      'value' => 'ST',
    ),
    15 => array(
      'title' => 'Schleswig-Holstein',
      'operator' => '=',
      'value' => 'SH',
    ),
    16 => array(
      'title' => 'Thüringen',
      'operator' => '=',
      'value' => 'TH',
    ),
  );
  /* Filterkriterium: Benutzer: Constituency (field_user_constituency) */
  $handler->display->display_options['filters']['field_user_constituency_tid']['id'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['filters']['field_user_constituency_tid']['field'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_constituency_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator_id'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['label'] = 'Wahlkreis';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['identifier'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_constituency_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_constituency_tid']['vocabulary'] = 'constituency';
  /* Filterkriterium: Benutzer (Historische Daten): Party (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_party_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator_id'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['label'] = 'Nach Partei filtern';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['identifier'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_party_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_party_tid']['vocabulary'] = 'party';
  /* Filterkriterium: Benutzer (Historische Daten): QuestionAnswerRatio (field_user_qanda_ratio) */
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['id'] = 'field_user_qanda_ratio_value';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['table'] = 'field_revision_field_user_qanda_ratio';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['field'] = 'field_user_qanda_ratio_value';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['value']['min'] = '0';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['value']['max'] = '100';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['operator_id'] = 'field_user_qanda_ratio_value_op';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['label'] = 'Antwortquote';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['operator'] = 'field_user_qanda_ratio_value_op';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['identifier'] = 'field_user_qanda_ratio_value';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  /* Filterkriterium: Benutzer (Historische Daten): Age (field_user_age) */
  $handler->display->display_options['filters']['field_user_age_value']['id'] = 'field_user_age_value';
  $handler->display->display_options['filters']['field_user_age_value']['table'] = 'field_revision_field_user_age';
  $handler->display->display_options['filters']['field_user_age_value']['field'] = 'field_user_age_value';
  $handler->display->display_options['filters']['field_user_age_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_user_age_value']['value']['min'] = '0';
  $handler->display->display_options['filters']['field_user_age_value']['value']['max'] = '90';
  $handler->display->display_options['filters']['field_user_age_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_age_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_age_value']['expose']['operator_id'] = 'field_user_age_value_op';
  $handler->display->display_options['filters']['field_user_age_value']['expose']['label'] = 'Alter';
  $handler->display->display_options['filters']['field_user_age_value']['expose']['operator'] = 'field_user_age_value_op';
  $handler->display->display_options['filters']['field_user_age_value']['expose']['identifier'] = 'field_user_age_value';
  $handler->display->display_options['filters']['field_user_age_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_age_value']['group_info']['label'] = 'Age (field_user_age)';
  $handler->display->display_options['filters']['field_user_age_value']['group_info']['identifier'] = 'field_user_age_value';
  $handler->display->display_options['filters']['field_user_age_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_user_age_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filterkriterium: Benutzer (Historische Daten): Gender (field_user_gender) */
  $handler->display->display_options['filters']['field_user_gender_value']['id'] = 'field_user_gender_value';
  $handler->display->display_options['filters']['field_user_gender_value']['table'] = 'field_revision_field_user_gender';
  $handler->display->display_options['filters']['field_user_gender_value']['field'] = 'field_user_gender_value';
  $handler->display->display_options['filters']['field_user_gender_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_gender_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['operator_id'] = 'field_user_gender_value_op';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['label'] = 'Geschlecht auswählen';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['operator'] = 'field_user_gender_value_op';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['identifier'] = 'field_user_gender_value';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    181527986 => 0,
    51622513 => 0,
    185431326 => 0,
    140336230 => 0,
    237793809 => 0,
  );
  $handler->display->display_options['path'] = 'profile/%/%';

  /* Display: Listenansicht */
  $handler = $view->new_display('attachment', 'Listenansicht', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '21';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: User revision: Vid */
  $handler->display->display_options['fields']['vid_1']['id'] = 'vid_1';
  $handler->display->display_options['fields']['vid_1']['table'] = 'user_revision';
  $handler->display->display_options['fields']['vid_1']['field'] = 'vid';
  $handler->display->display_options['fields']['vid_1']['label'] = '';
  $handler->display->display_options['fields']['vid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['vid_1']['element_label_colon'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_user_picture-revision_id_1',
    1 => 'field_user_fname-revision_id_1',
    2 => 'field_user_lname-revision_id_1',
    3 => 'field_user_party-revision_id',
    4 => 'field_user_questions_get-revision_id',
    5 => 'field_user_answers_give-revision_id',
    6 => 'nothing_2',
    7 => 'fieldset_1',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'profiles-list-compact-wrapper';
  /* Feld: Benutzer (Historische Daten): Profile picture */
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['id'] = 'field_user_picture-revision_id_1';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['table'] = 'field_revision_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['field'] = 'field_user_picture-revision_id';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['alter']['text'] = '[field_user_picture-revision_id_1]';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_user_picture-revision_id_1']['settings'] = array(
    'file_view_mode' => 'pw_file_portrait_m',
  );
  /* Feld: Excluded | User (historical data): First Name */
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['id'] = 'field_user_fname-revision_id_1';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['table'] = 'field_revision_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['field'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['ui_name'] = 'Excluded | User (historical data): First Name';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['empty'] = '[field_user_fname]';
  $handler->display->display_options['fields']['field_user_fname-revision_id_1']['hide_alter_empty'] = FALSE;
  /* Feld: Excluded | User (historical data): Last name */
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['id'] = 'field_user_lname-revision_id_1';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['table'] = 'field_revision_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['field'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['ui_name'] = 'Excluded | User (historical data): Last name';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['empty'] = '[field_user_lname]';
  $handler->display->display_options['fields']['field_user_lname-revision_id_1']['hide_alter_empty'] = FALSE;
  /* Feld: Benutzer (Historische Daten): Party */
  $handler->display->display_options['fields']['field_user_party-revision_id']['id'] = 'field_user_party-revision_id';
  $handler->display->display_options['fields']['field_user_party-revision_id']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['fields']['field_user_party-revision_id']['field'] = 'field_user_party-revision_id';
  $handler->display->display_options['fields']['field_user_party-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_party-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_party-revision_id']['alter']['text'] = '[field_user_fname-revision_id_1] [field_user_lname-revision_id_1], [field_user_party-revision_id]';
  $handler->display->display_options['fields']['field_user_party-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_party-revision_id']['element_wrapper_type'] = 'h4';
  $handler->display->display_options['fields']['field_user_party-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_party-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party-revision_id']['delta_offset'] = '0';
  /* Feld: Excluded | User (historical data): Questions Get */
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['id'] = 'field_user_questions_get-revision_id';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['table'] = 'field_revision_field_user_questions_get';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['field'] = 'field_user_questions_get-revision_id';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['ui_name'] = 'Excluded | User (historical data): Questions Get';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['alter']['text'] = '[field_user_questions_get-revision_id-value] Fragen';
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_questions_get-revision_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Excluded | User (historical data): Answers Give */
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['id'] = 'field_user_answers_give-revision_id';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['table'] = 'field_revision_field_user_answers_give';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['field'] = 'field_user_answers_give-revision_id';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['ui_name'] = 'Excluded | User (historical data): Answers Give';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['alter']['text'] = '[field_user_answers_give-revision_id-value] Antworten';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['element_wrapper_class'] = 'row push-bottom-s';
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_answers_give-revision_id']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Feld: Rewritten | Custom text: Questions, Answers */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Rewritten | Custom text: Questions, Answers';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[field_user_questions_get-revision_id], [field_user_answers_give-revision_id]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = FALSE;
  /* Feld: Global: Feldgruppe */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
    0 => 'field_user_picture-revision_id',
    1 => 'field_user_fname-revision_id',
    2 => 'field_user_lname-revision_id',
    3 => 'field_user_party-revision_id_1',
    4 => 'field_user_parliament-revision_id',
    5 => 'field_user_constituency-revision_id',
    6 => 'nothing',
    7 => 'nothing_1',
    8 => 'expression',
    9 => 'vid',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['classes'] = 'element-hidden profile-list-compact-info';
  /* Feld: Benutzer (Historische Daten): Profile picture */
  $handler->display->display_options['fields']['field_user_picture-revision_id']['id'] = 'field_user_picture-revision_id';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['table'] = 'field_revision_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['field'] = 'field_user_picture-revision_id';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['alter']['path'] = 'profile/[name]/archive/[vid_1]';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['element_wrapper_class'] = 'profile-image img-outline';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture-revision_id']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture-revision_id']['settings'] = array(
    'image_style' => 'pw_portrait_l__normal',
    'image_link' => '',
  );
  /* Feld: Benutzer (Historische Daten): First Name */
  $handler->display->display_options['fields']['field_user_fname-revision_id']['id'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['table'] = 'field_revision_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['field'] = 'field_user_fname-revision_id';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['alter']['text'] = '<h3>[field_user_fname-revision_id]';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname-revision_id']['empty'] = '<h3>[field_user_fname]';
  $handler->display->display_options['fields']['field_user_fname-revision_id']['hide_alter_empty'] = FALSE;
  /* Feld: Benutzer (Historische Daten): Last name */
  $handler->display->display_options['fields']['field_user_lname-revision_id']['id'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['table'] = 'field_revision_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['field'] = 'field_user_lname-revision_id';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname-revision_id']['alter']['text'] = '[field_user_lname-revision_id]</h3>';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname-revision_id']['empty'] = '[field_user_lname]</h3>';
  $handler->display->display_options['fields']['field_user_lname-revision_id']['hide_alter_empty'] = FALSE;
  /* Feld: Benutzer (Historische Daten): Party */
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['id'] = 'field_user_party-revision_id_1';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['field'] = 'field_user_party-revision_id';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['element_wrapper_class'] = 'row party push-bottom-xxs';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_party-revision_id_1']['delta_offset'] = '0';
  /* Feld: Feld (Historische Daten): Parliament */
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['id'] = 'field_user_parliament-revision_id';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['table'] = 'field_revision_field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['field'] = 'field_user_parliament-revision_id';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['element_wrapper_class'] = 'row';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_parliament-revision_id']['delta_offset'] = '0';
  /* Feld: Benutzer (Historische Daten): Constituency */
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['id'] = 'field_user_constituency-revision_id';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['table'] = 'field_revision_field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['field'] = 'field_user_constituency-revision_id';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['element_wrapper_class'] = 'row';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_user_constituency-revision_id']['delta_offset'] = '0';
  /* Feld: Reused | Questions get */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Reused | Questions get';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_user_questions_get-revision_id]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'row';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Feld: Reused | Answers give */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Reused | Answers give';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_user_answers_give-revision_id]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'row push-bottom-s';
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Feld: Global: Math expression: Response rate */
  $handler->display->display_options['fields']['expression']['id'] = 'expression';
  $handler->display->display_options['fields']['expression']['table'] = 'views';
  $handler->display->display_options['fields']['expression']['field'] = 'expression';
  $handler->display->display_options['fields']['expression']['ui_name'] = 'Global: Math expression: Response rate';
  $handler->display->display_options['fields']['expression']['label'] = '';
  $handler->display->display_options['fields']['expression']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['expression']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['expression']['element_wrapper_class'] = 'row push-bottom-xs';
  $handler->display->display_options['fields']['expression']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['expression']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['expression']['precision'] = '1';
  $handler->display->display_options['fields']['expression']['decimal'] = ',';
  $handler->display->display_options['fields']['expression']['separator'] = '';
  $handler->display->display_options['fields']['expression']['suffix'] = '% Antwortquote';
  $handler->display->display_options['fields']['expression']['expression'] = '[field_user_answers_give-revision_id] / [field_user_questions_get-revision_id] ';
  /* Feld: Link to profile */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'user_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['ui_name'] = 'Link to profile';
  $handler->display->display_options['fields']['vid']['label'] = '';
  $handler->display->display_options['fields']['vid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['vid']['alter']['text'] = 'Profil besuchen';
  $handler->display->display_options['fields']['vid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['vid']['alter']['path'] = 'profile/[name]/archive/[vid_1]';
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['vid']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['vid']['element_wrapper_class'] = 'link-profile row bg-white';
  $handler->display->display_options['fields']['vid']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Benutzer: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Aktiv';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Filterkriterium: Benutzer (Historische Daten): First Letter of Lastname (field_user_first_letter_lname) */
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['id'] = 'field_user_first_letter_lname_value';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['table'] = 'field_revision_field_user_first_letter_lname';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['field'] = 'field_user_first_letter_lname_value';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['operator_id'] = 'field_user_first_letter_lname_value_op';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['label'] = 'user_first_letter_lname (field_user_first_letter_lname)';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['operator'] = 'field_user_first_letter_lname_value_op';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['identifier'] = 'field_user_first_letter_lname_value';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['label'] = 'Nach Namen filtern';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['identifier'] = 'field_user_first_letter_lname_value';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_letter_lname_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'A',
      'operator' => '=',
      'value' => 'A',
    ),
    2 => array(
      'title' => 'B',
      'operator' => '=',
      'value' => 'B',
    ),
    3 => array(
      'title' => 'C',
      'operator' => '=',
      'value' => 'C',
    ),
    4 => array(
      'title' => 'D',
      'operator' => '=',
      'value' => 'D',
    ),
    5 => array(
      'title' => 'E',
      'operator' => '=',
      'value' => 'E',
    ),
    6 => array(
      'title' => 'F',
      'operator' => '=',
      'value' => 'F',
    ),
    7 => array(
      'title' => 'G',
      'operator' => '=',
      'value' => 'G',
    ),
    8 => array(
      'title' => 'H',
      'operator' => '=',
      'value' => 'H',
    ),
    9 => array(
      'title' => 'I',
      'operator' => '=',
      'value' => 'I',
    ),
    10 => array(
      'title' => 'J',
      'operator' => '=',
      'value' => 'J',
    ),
    11 => array(
      'title' => 'K',
      'operator' => '=',
      'value' => 'K',
    ),
    12 => array(
      'title' => 'L',
      'operator' => '=',
      'value' => 'L',
    ),
    13 => array(
      'title' => 'M',
      'operator' => '=',
      'value' => 'M',
    ),
    14 => array(
      'title' => 'N',
      'operator' => '=',
      'value' => 'N',
    ),
    15 => array(
      'title' => 'O',
      'operator' => '=',
      'value' => 'O',
    ),
    16 => array(
      'title' => 'P',
      'operator' => '=',
      'value' => 'P',
    ),
    17 => array(
      'title' => 'Q',
      'operator' => '=',
      'value' => 'Q',
    ),
    18 => array(
      'title' => 'R',
      'operator' => '=',
      'value' => 'R',
    ),
    19 => array(
      'title' => 'S',
      'operator' => '=',
      'value' => 'S',
    ),
    20 => array(
      'title' => 'T',
      'operator' => '=',
      'value' => 'T',
    ),
    21 => array(
      'title' => 'U',
      'operator' => '=',
      'value' => 'U',
    ),
    22 => array(
      'title' => 'V',
      'operator' => '=',
      'value' => 'V',
    ),
    23 => array(
      'title' => 'W',
      'operator' => '=',
      'value' => 'W',
    ),
    24 => array(
      'title' => 'X',
      'operator' => '=',
      'value' => 'X',
    ),
    25 => array(
      'title' => 'Y',
      'operator' => '=',
      'value' => 'Y',
    ),
    26 => array(
      'title' => 'Z',
      'operator' => '=',
      'value' => 'Z',
    ),
  );
  /* Filterkriterium: Benutzer: Constituency (field_user_constituency) */
  $handler->display->display_options['filters']['field_user_constituency_tid']['id'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['table'] = 'field_data_field_user_constituency';
  $handler->display->display_options['filters']['field_user_constituency_tid']['field'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_constituency_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator_id'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['label'] = 'Bundesland wählen';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['operator'] = 'field_user_constituency_tid_op';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['identifier'] = 'field_user_constituency_tid';
  $handler->display->display_options['filters']['field_user_constituency_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    181527986 => 0,
    51622513 => 0,
    185431326 => 0,
    140336230 => 0,
    237793809 => 0,
  );
  $handler->display->display_options['filters']['field_user_constituency_tid']['vocabulary'] = 'constituency';
  /* Filterkriterium: Benutzer (Historische Daten): Party (field_user_party) */
  $handler->display->display_options['filters']['field_user_party_tid']['id'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['table'] = 'field_revision_field_user_party';
  $handler->display->display_options['filters']['field_user_party_tid']['field'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_party_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator_id'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['label'] = 'Nach Partei filtern';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['operator'] = 'field_user_party_tid_op';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['identifier'] = 'field_user_party_tid';
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_party_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_party_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_party_tid']['vocabulary'] = 'party';
  /* Filterkriterium: Benutzer (Historische Daten): QuestionAnswerRatio (field_user_qanda_ratio) */
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['id'] = 'field_user_qanda_ratio_value';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['table'] = 'field_revision_field_user_qanda_ratio';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['field'] = 'field_user_qanda_ratio_value';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['value']['min'] = '0';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['value']['max'] = '100';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['operator_id'] = 'field_user_qanda_ratio_value_op';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['label'] = 'Antwortquote';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['operator'] = 'field_user_qanda_ratio_value_op';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['identifier'] = 'field_user_qanda_ratio_value';
  $handler->display->display_options['filters']['field_user_qanda_ratio_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  /* Filterkriterium: Benutzer (Historische Daten): Age (field_user_age) */
  $handler->display->display_options['filters']['field_user_age_value']['id'] = 'field_user_age_value';
  $handler->display->display_options['filters']['field_user_age_value']['table'] = 'field_revision_field_user_age';
  $handler->display->display_options['filters']['field_user_age_value']['field'] = 'field_user_age_value';
  $handler->display->display_options['filters']['field_user_age_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_user_age_value']['value']['min'] = '20';
  $handler->display->display_options['filters']['field_user_age_value']['value']['max'] = '70';
  $handler->display->display_options['filters']['field_user_age_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_age_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_age_value']['expose']['operator_id'] = 'field_user_age_value_op';
  $handler->display->display_options['filters']['field_user_age_value']['expose']['label'] = 'Alter';
  $handler->display->display_options['filters']['field_user_age_value']['expose']['operator'] = 'field_user_age_value_op';
  $handler->display->display_options['filters']['field_user_age_value']['expose']['identifier'] = 'field_user_age_value';
  $handler->display->display_options['filters']['field_user_age_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['field_user_age_value']['group_info']['label'] = 'Age (field_user_age)';
  $handler->display->display_options['filters']['field_user_age_value']['group_info']['identifier'] = 'field_user_age_value';
  $handler->display->display_options['filters']['field_user_age_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_user_age_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filterkriterium: Benutzer (Historische Daten): Gender (field_user_gender) */
  $handler->display->display_options['filters']['field_user_gender_value']['id'] = 'field_user_gender_value';
  $handler->display->display_options['filters']['field_user_gender_value']['table'] = 'field_revision_field_user_gender';
  $handler->display->display_options['filters']['field_user_gender_value']['field'] = 'field_user_gender_value';
  $handler->display->display_options['filters']['field_user_gender_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_gender_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['operator_id'] = 'field_user_gender_value_op';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['label'] = 'Geschlecht auswählen';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['operator'] = 'field_user_gender_value_op';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['identifier'] = 'field_user_gender_value';
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_user_gender_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    181527986 => 0,
    51622513 => 0,
    185431326 => 0,
    140336230 => 0,
    237793809 => 0,
  );
  /* Filterkriterium: Datum: Between Dates (user_revision) */
  $handler->display->display_options['filters']['between_date_filter']['id'] = 'between_date_filter';
  $handler->display->display_options['filters']['between_date_filter']['table'] = 'user_revision';
  $handler->display->display_options['filters']['between_date_filter']['field'] = 'between_date_filter';
  $handler->display->display_options['filters']['between_date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['between_date_filter']['expose']['operator_id'] = 'between_date_filter_op';
  $handler->display->display_options['filters']['between_date_filter']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['between_date_filter']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['between_date_filter']['expose']['operator'] = 'between_date_filter_op';
  $handler->display->display_options['filters']['between_date_filter']['expose']['identifier'] = 'between_date_filter';
  $handler->display->display_options['filters']['between_date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
  );
  $handler->display->display_options['filters']['between_date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['between_date_filter']['start_date_field'] = 'field_revision_field_user_valid.field_user_valid_value';
  $handler->display->display_options['filters']['between_date_filter']['end_date_field'] = 'field_revision_field_user_valid.field_user_valid_value2';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'grid' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_exposed_filters'] = TRUE;
  $handler->display->display_options['inherit_pager'] = TRUE;
  $export['profile_list_rev'] = $view;

  $view = new view();
  $view->name = 'pw_user_blocks';
  $view->description = 'Blocks for the Sidebar';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'PW User Blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'weiterlesen';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Feld: Benutzer: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname']['element_default_classes'] = FALSE;
  /* Kontextfilter: Benutzer: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = TRUE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  /* Filterkriterium: Benutzer: Aktiv */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Wrong Data */
  $handler = $view->new_display('block', 'Wrong Data', 'user_wrong_data');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Daten von [field_user_fname] [field_user_lname] nicht korrekt?';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Excluded | User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['ui_name'] = 'Excluded | User: Uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Feld: Excluded | User: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['ui_name'] = 'Excluded | User: First Name';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Excluded | User: Last Name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['ui_name'] = 'Excluded | User: Last Name';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname']['element_default_classes'] = FALSE;
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Wenn Ihnen ein Fehler bzgl. der Angaben zu [field_user_fname] [field_user_lname] aufgefallen ist, teilen Sie uns diesen bitte über das Formular mit:';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'icon-edit';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Feld: Link */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Link';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Benachrichtigen Sie uns';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'contact?width=600&height=400';
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['link_class'] = 'colorbox-node';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'text-right';
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;

  /* Display: Profile API */
  $handler = $view->new_display('block', 'Profile API', 'api_profile');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '[field_user_fname] [field_user_lname] als XML';
  $handler->display->display_options['display_description'] = 'provides a link to the API';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Excluded | User: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'field_data_field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['ui_name'] = 'Excluded | User: First Name';
  $handler->display->display_options['fields']['field_user_fname']['label'] = '';
  $handler->display->display_options['fields']['field_user_fname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_fname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_fname']['element_default_classes'] = FALSE;
  /* Feld: Excluded | User: Last Name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'field_data_field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['ui_name'] = 'Excluded | User: Last Name';
  $handler->display->display_options['fields']['field_user_lname']['label'] = '';
  $handler->display->display_options['fields']['field_user_lname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_lname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_lname']['element_default_classes'] = FALSE;
  /* Feld: Excluded | User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['ui_name'] = 'Excluded | User: Name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Feld: Global: Benutzerdefinierter Text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Daten zu [field_user_fname] [field_user_lname] stehen Ihnen auch als XML zur Verfügung.';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'p';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'icon-edit';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Feld: Link */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Link';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Link zur API';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'api/profile/[name]/profile.xml';
  $handler->display->display_options['fields']['nothing_1']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'text-right';
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  $export['pw_user_blocks'] = $view;

  $view = new view();
  $view->name = 'user_tweets';
  $view->description = 'Displays Twitter.com status messages for users who have associated Twitter accounts.';
  $view->tag = '';
  $view->base_table = 'twitter';
  $view->human_name = 'User Tweets';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Tweets */
  $handler = $view->new_display('default', 'Tweets', 'default');
  $handler->display->display_options['css_class'] = 'twitter';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'zum Twitterkanal';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'profile_image_url' => 'profile_image_url',
    'text' => 'text',
    'created_time' => 'text',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'profile_image_url' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'text' => array(
      'sortable' => 0,
      'separator' => ' &#8212; ',
    ),
    'created_time' => array(
      'sortable' => 0,
      'separator' => '',
    ),
  );
  /* Feld: Twitter: Profil-Bild */
  $handler->display->display_options['fields']['profile_image_url']['id'] = 'profile_image_url';
  $handler->display->display_options['fields']['profile_image_url']['table'] = 'twitter_account';
  $handler->display->display_options['fields']['profile_image_url']['field'] = 'profile_image_url';
  $handler->display->display_options['fields']['profile_image_url']['label'] = '';
  /* Feld: Twitter: Text der Nachricht */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'twitter';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['link_urls'] = 1;
  $handler->display->display_options['fields']['text']['link_usernames'] = 1;
  $handler->display->display_options['fields']['text']['link_hashtags'] = 1;
  /* Feld: Twitter: Erstellungszeit */
  $handler->display->display_options['fields']['created_time']['id'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['table'] = 'twitter';
  $handler->display->display_options['fields']['created_time']['field'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['label'] = '';
  $handler->display->display_options['fields']['created_time']['date_format'] = 'time ago';
  /* Sortierkriterien: Twitter: Erstellungszeit */
  $handler->display->display_options['sorts']['created_time']['id'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['table'] = 'twitter';
  $handler->display->display_options['sorts']['created_time']['field'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['order'] = 'DESC';
  /* Filterkriterium: Twitter: Geschützter Status */
  $handler->display->display_options['filters']['protected']['id'] = 'protected';
  $handler->display->display_options['filters']['protected']['table'] = 'twitter_account';
  $handler->display->display_options['filters']['protected']['field'] = 'protected';
  $handler->display->display_options['filters']['protected']['value'] = 0;
  $handler->display->display_options['filters']['protected']['group'] = '0';
  $handler->display->display_options['filters']['protected']['expose']['operator'] = FALSE;

  /* Display: a_watch Block */
  $handler = $view->new_display('block', 'a_watch Block', 'a_watch');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Twitter Ticker';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'https://twitter.com/a_watch';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'twitter-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'text' => 'text',
    'created_time' => 'created_time',
  );
  $handler->display->display_options['row_options']['separator'] = ' &#8212; ';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Twitter: Erstellungszeit */
  $handler->display->display_options['fields']['created_time_1']['id'] = 'created_time_1';
  $handler->display->display_options['fields']['created_time_1']['table'] = 'twitter';
  $handler->display->display_options['fields']['created_time_1']['field'] = 'created_time';
  $handler->display->display_options['fields']['created_time_1']['label'] = '';
  $handler->display->display_options['fields']['created_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_time_1']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['created_time_1']['element_wrapper_class'] = 'light';
  $handler->display->display_options['fields']['created_time_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created_time_1']['date_format'] = 'date_and_time';
  /* Feld: Twitter: Text der Nachricht */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'twitter';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['link_urls'] = 1;
  $handler->display->display_options['fields']['text']['link_usernames'] = 1;
  $handler->display->display_options['fields']['text']['link_hashtags'] = 1;
  $handler->display->display_options['fields']['text']['link_attributes'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterium: Twitter: Geschützter Status */
  $handler->display->display_options['filters']['protected']['id'] = 'protected';
  $handler->display->display_options['filters']['protected']['table'] = 'twitter_account';
  $handler->display->display_options['filters']['protected']['field'] = 'protected';
  $handler->display->display_options['filters']['protected']['value'] = 0;
  $handler->display->display_options['filters']['protected']['group'] = '0';
  $handler->display->display_options['filters']['protected']['expose']['operator'] = FALSE;
  /* Filterkriterium: Twitter: Login-name */
  $handler->display->display_options['filters']['screen_name']['id'] = 'screen_name';
  $handler->display->display_options['filters']['screen_name']['table'] = 'twitter_account';
  $handler->display->display_options['filters']['screen_name']['field'] = 'screen_name';
  $handler->display->display_options['filters']['screen_name']['value'] = 'a_watch';
  $handler->display->display_options['block_description'] = 'Tweets';

  /* Display: User Tweets */
  $handler = $view->new_display('block', 'User Tweets', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '[name] auf Twitter';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'twitter clear clearfix push-bottom-l relative';
  $handler->display->display_options['display_description'] = 'User Tweets Block on Profile';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'pw-list-item-light clear clearfix';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Kopfbereich: Global: Textbereich */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a href="https://twitter.com/[screen_name]"><span class="float-left push-right-s push-bottom-s"><img src="/sites/abgeordnetenwatch.de/files/Twitter_logo_blue.png" width="48" height="48" alt="" /></span><span class="pw-twitter-name">[name]</span>
<span class="pw-twitter-screenname">[screen_name]</span></a>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Fußbereich: Global: Textbereich */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="text-right">[follow] [name] <?php print t(\'on Twitter\'); ?></div>';
  $handler->display->display_options['footer']['area']['format'] = 'php_code';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Feld: Exlcuded | Twitter Follow */
  $handler->display->display_options['fields']['follow']['id'] = 'follow';
  $handler->display->display_options['fields']['follow']['table'] = 'twitter';
  $handler->display->display_options['fields']['follow']['field'] = 'follow';
  $handler->display->display_options['fields']['follow']['ui_name'] = 'Exlcuded | Twitter Follow';
  $handler->display->display_options['fields']['follow']['label'] = '';
  $handler->display->display_options['fields']['follow']['exclude'] = TRUE;
  $handler->display->display_options['fields']['follow']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['follow']['element_label_colon'] = FALSE;
  /* Feld: Excluded |  Twitter Login Name */
  $handler->display->display_options['fields']['screen_name']['id'] = 'screen_name';
  $handler->display->display_options['fields']['screen_name']['table'] = 'twitter';
  $handler->display->display_options['fields']['screen_name']['field'] = 'screen_name';
  $handler->display->display_options['fields']['screen_name']['ui_name'] = 'Excluded |  Twitter Login Name';
  $handler->display->display_options['fields']['screen_name']['label'] = '';
  $handler->display->display_options['fields']['screen_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['screen_name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['screen_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['screen_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['screen_name']['hide_alter_empty'] = FALSE;
  /* Feld: Excluded | Twitter Full name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'twitter_account';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['ui_name'] = 'Excluded | Twitter Full name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Feld: Twitter: Text der Nachricht */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'twitter';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['link_urls'] = 1;
  $handler->display->display_options['fields']['text']['link_usernames'] = 1;
  $handler->display->display_options['fields']['text']['link_hashtags'] = 1;
  /* Feld: Excluded | Twitter: Erstellungszeit */
  $handler->display->display_options['fields']['created_time']['id'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['table'] = 'twitter';
  $handler->display->display_options['fields']['created_time']['field'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['ui_name'] = 'Excluded | Twitter: Erstellungszeit';
  $handler->display->display_options['fields']['created_time']['label'] = '';
  $handler->display->display_options['fields']['created_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_time']['date_format'] = 'time ago';
  /* Feld: Twitter: Web Intents */
  $handler->display->display_options['fields']['web_intents']['id'] = 'web_intents';
  $handler->display->display_options['fields']['web_intents']['table'] = 'twitter';
  $handler->display->display_options['fields']['web_intents']['field'] = 'web_intents';
  $handler->display->display_options['fields']['web_intents']['label'] = '';
  $handler->display->display_options['fields']['web_intents']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['web_intents']['alter']['text'] = '[created_time] [web_intents]';
  $handler->display->display_options['fields']['web_intents']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['web_intents']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['web_intents']['element_wrapper_class'] = 'footer small';
  $handler->display->display_options['fields']['web_intents']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Kontextfilter: Benutzer: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $export['user_tweets'] = $view;

  return $export;
}
