<?php
/**
 * @file
 * pw_search_api.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function pw_search_api_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'politician_search_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_politician_index';
  $view->human_name = 'Politician Search View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Suche nach Politikern';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'none';
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
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Für Ihre Suchanfrage liegen keine Ergebnisse vor.';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Feld: Indexed Benutzer: Benutzer-ID */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'search_api_index_politician_index';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* Feld: Indexed Benutzer: Address » Vollständiger Name */
  $handler->display->display_options['fields']['field_user_address_name_line']['id'] = 'field_user_address_name_line';
  $handler->display->display_options['fields']['field_user_address_name_line']['table'] = 'search_api_index_politician_index';
  $handler->display->display_options['fields']['field_user_address_name_line']['field'] = 'field_user_address_name_line';
  $handler->display->display_options['fields']['field_user_address_name_line']['link_to_entity'] = 0;
  /* Feld: Indexed Benutzer: Constituency */
  $handler->display->display_options['fields']['field_user_constituency']['id'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['table'] = 'search_api_index_politician_index';
  $handler->display->display_options['fields']['field_user_constituency']['field'] = 'field_user_constituency';
  $handler->display->display_options['fields']['field_user_constituency']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_user_constituency']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_user_constituency']['bypass_access'] = 0;
  /* Feld: Indexed Benutzer: First Name */
  $handler->display->display_options['fields']['field_user_fname']['id'] = 'field_user_fname';
  $handler->display->display_options['fields']['field_user_fname']['table'] = 'search_api_index_politician_index';
  $handler->display->display_options['fields']['field_user_fname']['field'] = 'field_user_fname';
  /* Feld: Indexed Benutzer: Last name */
  $handler->display->display_options['fields']['field_user_lname']['id'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['table'] = 'search_api_index_politician_index';
  $handler->display->display_options['fields']['field_user_lname']['field'] = 'field_user_lname';
  $handler->display->display_options['fields']['field_user_lname']['label'] = 'Nachname';
  /* Feld: Indexed Benutzer: Parliament */
  $handler->display->display_options['fields']['field_user_parliament']['id'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['table'] = 'search_api_index_politician_index';
  $handler->display->display_options['fields']['field_user_parliament']['field'] = 'field_user_parliament';
  $handler->display->display_options['fields']['field_user_parliament']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_user_parliament']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_user_parliament']['bypass_access'] = 0;
  /* Feld: Indexed Benutzer: Party */
  $handler->display->display_options['fields']['field_user_party']['id'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['table'] = 'search_api_index_politician_index';
  $handler->display->display_options['fields']['field_user_party']['field'] = 'field_user_party';
  $handler->display->display_options['fields']['field_user_party']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_user_party']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_user_party']['bypass_access'] = 0;
  /* Feld: Parliament: Name (indexed) */
  $handler->display->display_options['fields']['field_user_parliament_name']['id'] = 'field_user_parliament_name';
  $handler->display->display_options['fields']['field_user_parliament_name']['table'] = 'search_api_index_politician_index';
  $handler->display->display_options['fields']['field_user_parliament_name']['field'] = 'field_user_parliament_name';
  $handler->display->display_options['fields']['field_user_parliament_name']['link_to_entity'] = 0;
  /* Feld: Indexed Benutzer: First Letter of Lastname */
  $handler->display->display_options['fields']['field_user_first_letter_lname']['id'] = 'field_user_first_letter_lname';
  $handler->display->display_options['fields']['field_user_first_letter_lname']['table'] = 'search_api_index_politician_index';
  $handler->display->display_options['fields']['field_user_first_letter_lname']['field'] = 'field_user_first_letter_lname';
  /* Kontextfilter: Indexed Benutzer: Benutzerrollen */
  $handler->display->display_options['arguments']['roles']['id'] = 'roles';
  $handler->display->display_options['arguments']['roles']['table'] = 'search_api_index_politician_index';
  $handler->display->display_options['arguments']['roles']['field'] = 'roles';
  $handler->display->display_options['arguments']['roles']['exception']['value'] = 'alle';
  $handler->display->display_options['arguments']['roles']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['roles']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['roles']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['roles']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['roles']['not'] = 0;
  /* Filterkriterium: Suche: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_politician_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'k';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    29859578 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'field_user_constituency:field_constituency_area_codes:name' => 'field_user_constituency:field_constituency_area_codes:name',
    'field_user_constituency:name' => 'field_user_constituency:name',
    'field_user_fname' => 'field_user_fname',
    'field_user_lname' => 'field_user_lname',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'suche/%';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $translatables['politician_search_view'] = array(
    t('Master'),
    t('Suche nach Politikern'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('weiter'),
    t('letzte Seite »'),
    t('Für Ihre Suchanfrage liegen keine Ergebnisse vor.'),
    t('Benutzer-ID'),
    t('.'),
    t(','),
    t('Address » Vollständiger Name'),
    t('Constituency'),
    t('First Name'),
    t('Nachname'),
    t('Parliament'),
    t('Party'),
    t('Name (indexed)'),
    t('First Letter of Lastname'),
    t('Alle'),
    t('Page'),
    t('Block'),
  );
  $export['politician_search_view'] = $view;

  $view = new view();
  $view->name = 'pw_search_api_main';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_multi';
  $view->human_name = 'PW Search API Main';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Suchergebnisse';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Jetzt suchen';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Erweiterte Optionen',
    ),
    'search_api_multi_fulltext' => array(
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
    'main_index_type' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => 'All|Ganze Plattform durchsuchen
Alle|Ganze Plattform durchsuchen
0|Ganze Plattform durchsuchen 0',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'managed_content';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'pw-list-item clearfix';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'search_api_multi';
  $handler->display->display_options['row_options']['view_mode'] = array(
    'node' => 'search_result',
    'user' => 'search_result',
  );
  /* Verhalten, wenn keine Ergebnisse vorliegen: Global: Textbereich */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Suche erfolglos';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Leider liegen für Ihre Anfrage keine Suchergebnisse vor.';
  $handler->display->display_options['empty']['area']['format'] = 'managed_content';
  /* Feld: Suche: Node Index results */
  $handler->display->display_options['fields']['node_index']['id'] = 'node_index';
  $handler->display->display_options['fields']['node_index']['table'] = 'search_api_multi';
  $handler->display->display_options['fields']['node_index']['field'] = 'node_index';
  /* Sortierkriterien: Politician Index: URI (indexed) */
  $handler->display->display_options['sorts']['politician_index_search_api_url']['id'] = 'politician_index_search_api_url';
  $handler->display->display_options['sorts']['politician_index_search_api_url']['table'] = 'search_api_multi';
  $handler->display->display_options['sorts']['politician_index_search_api_url']['field'] = 'politician_index_search_api_url';
  /* Sortierkriterien: Main Index: Ordinal date for search results (indexed) */
  $handler->display->display_options['sorts']['main_index_field_search_sort_date']['id'] = 'main_index_field_search_sort_date';
  $handler->display->display_options['sorts']['main_index_field_search_sort_date']['table'] = 'search_api_multi';
  $handler->display->display_options['sorts']['main_index_field_search_sort_date']['field'] = 'main_index_field_search_sort_date';
  $handler->display->display_options['sorts']['main_index_field_search_sort_date']['order'] = 'DESC';
  /* Filterkriterium: Suche: Fulltext search */
  $handler->display->display_options['filters']['search_api_multi_fulltext']['id'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['table'] = 'search_api_multi';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['field'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator_id'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['label'] = 'Suchbegriff';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['identifier'] = 's';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['remember_roles'] = array(
    2 => 0,
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    29859578 => 0,
  );
  /* Filterkriterium: Suche: Index */
  $handler->display->display_options['filters']['search_api_multi_index']['id'] = 'search_api_multi_index';
  $handler->display->display_options['filters']['search_api_multi_index']['table'] = 'search_api_multi';
  $handler->display->display_options['filters']['search_api_multi_index']['field'] = 'search_api_multi_index';
  $handler->display->display_options['filters']['search_api_multi_index']['value'] = array(
    'politician_index' => 'politician_index',
    'main_index' => 'main_index',
  );
  /* Filterkriterium: Main Index: Inhaltstyp (indexed) */
  $handler->display->display_options['filters']['main_index_type']['id'] = 'main_index_type';
  $handler->display->display_options['filters']['main_index_type']['table'] = 'search_api_multi';
  $handler->display->display_options['filters']['main_index_type']['field'] = 'main_index_type';
  $handler->display->display_options['filters']['main_index_type']['value'] = array(
    'poll' => 'poll',
    'blogpost' => 'blogpost',
    'page' => 'page',
    'dialogue' => 'dialogue',
    'pw_petition' => 'pw_petition',
  );
  $handler->display->display_options['filters']['main_index_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['main_index_type']['expose']['operator_id'] = 'main_index_type_op';
  $handler->display->display_options['filters']['main_index_type']['expose']['label'] = 'Ergebnis beschränken auf';
  $handler->display->display_options['filters']['main_index_type']['expose']['operator'] = 'main_index_type_op';
  $handler->display->display_options['filters']['main_index_type']['expose']['identifier'] = 'typ';
  $handler->display->display_options['filters']['main_index_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    29859578 => 0,
  );
  $handler->display->display_options['filters']['main_index_type']['expose']['reduce'] = 1;
  $handler->display->display_options['filters']['main_index_type']['group_info']['identifier'] = 'blog';
  $handler->display->display_options['filters']['main_index_type']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['main_index_type']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Inhaltstyp',
      'operator' => '=',
      'value' => array(
        'poll' => 'poll',
        'blogpost' => 'blogpost',
        'dialogue' => 'dialogue',
        'page' => 'page',
        'pw_petition' => 'pw_petition',
        'announcement' => 0,
        'calendar_entry' => 0,
        'committee_membership' => 0,
        'pw_kc_position' => 0,
        'pw_kc_thesis' => 0,
        'newsletter' => 0,
        'press_release' => 0,
        'press_article' => 0,
        'sidejob' => 0,
        'pw_slider' => 0,
        'speech' => 0,
        'trustee' => 0,
        'vote' => 0,
        'election_programme' => 0,
        'webform' => 0,
      ),
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'suche';
  $translatables['pw_search_api_main'] = array(
    t('Master'),
    t('Suchergebnisse'),
    t('mehr'),
    t('Jetzt suchen'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Wählen Sie eine beliebige Filter und klicken Sie auf Anwenden, um Ergebnisse zu sehen'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('weiter'),
    t('letzte Seite »'),
    t('Suche erfolglos'),
    t('Leider liegen für Ihre Anfrage keine Suchergebnisse vor.'),
    t('Node Index results'),
    t('Suchbegriff'),
    t('Ergebnis beschränken auf'),
    t('Page'),
  );
  $export['pw_search_api_main'] = $view;

  $view = new view();
  $view->name = 'vote_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_node_index';
  $view->human_name = 'Vote Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Vote Search';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mehr';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Anwenden';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Zurücksetzen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortieren nach';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Aufsteigend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Absteigend';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Erweiterte Optionen',
    ),
    'search_api_views_fulltext' => array(
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
    'field_vote_user_field_user_party' => array(
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
    'field_vote' => array(
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
          'filter_rewrite_values' => 'yes|dafür gestimmt
no|dagegen gestimmt
abstain|enthalten
no-show|nicht beteiligt',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'managed_content';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemente pro Seite';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« erste Seite';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ vorherige Seite';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'weiter';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'letzte Seite »';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'pw-list-seperated';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Feld: Indexed Inhalt: Beitrags-ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Feld: Indexed Inhalt: Parliament */
  $handler->display->display_options['fields']['field_parliament']['id'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_parliament']['field'] = 'field_parliament';
  $handler->display->display_options['fields']['field_parliament']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_parliament']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_parliament']['bypass_access'] = 0;
  /* Feld: Indexed Inhalt: Politician */
  $handler->display->display_options['fields']['field_politician']['id'] = 'field_politician';
  $handler->display->display_options['fields']['field_politician']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_politician']['field'] = 'field_politician';
  $handler->display->display_options['fields']['field_politician']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_politician']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_politician']['bypass_access'] = 0;
  /* Feld: Indexed Inhalt: The main body text » Text */
  $handler->display->display_options['fields']['body_value']['id'] = 'body_value';
  $handler->display->display_options['fields']['body_value']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['body_value']['field'] = 'body_value';
  $handler->display->display_options['fields']['body_value']['link_to_entity'] = 0;
  /* Feld: Indexed Inhalt: Node Reference */
  $handler->display->display_options['fields']['field_vote_node']['id'] = 'field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_node']['field'] = 'field_vote_node';
  $handler->display->display_options['fields']['field_vote_node']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_vote_node']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_vote_node']['bypass_access'] = 0;
  /* Feld: Politician Reference: Constituency (indexed) */
  $handler->display->display_options['fields']['field_vote_user_field_user_constituency']['id'] = 'field_vote_user_field_user_constituency';
  $handler->display->display_options['fields']['field_vote_user_field_user_constituency']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_user_field_user_constituency']['field'] = 'field_vote_user_field_user_constituency';
  $handler->display->display_options['fields']['field_vote_user_field_user_constituency']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_vote_user_field_user_constituency']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_vote_user_field_user_constituency']['bypass_access'] = 0;
  /* Feld: Politician Reference: First Name (indexed) */
  $handler->display->display_options['fields']['field_vote_user_field_user_fname']['id'] = 'field_vote_user_field_user_fname';
  $handler->display->display_options['fields']['field_vote_user_field_user_fname']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_user_field_user_fname']['field'] = 'field_vote_user_field_user_fname';
  /* Feld: Politician Reference: Gender (indexed) */
  $handler->display->display_options['fields']['field_vote_user_field_user_gender']['id'] = 'field_vote_user_field_user_gender';
  $handler->display->display_options['fields']['field_vote_user_field_user_gender']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_user_field_user_gender']['field'] = 'field_vote_user_field_user_gender';
  /* Feld: Politician Reference: Last name (indexed) */
  $handler->display->display_options['fields']['field_vote_user_field_user_lname']['id'] = 'field_vote_user_field_user_lname';
  $handler->display->display_options['fields']['field_vote_user_field_user_lname']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_user_field_user_lname']['field'] = 'field_vote_user_field_user_lname';
  /* Feld: Politician Reference: Name (indexed) */
  $handler->display->display_options['fields']['field_vote_user_name']['id'] = 'field_vote_user_name';
  $handler->display->display_options['fields']['field_vote_user_name']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_user_name']['field'] = 'field_vote_user_name';
  $handler->display->display_options['fields']['field_vote_user_name']['link_to_entity'] = 0;
  /* Feld: Politician Reference: Parliament (indexed) */
  $handler->display->display_options['fields']['field_vote_user_field_user_parliament']['id'] = 'field_vote_user_field_user_parliament';
  $handler->display->display_options['fields']['field_vote_user_field_user_parliament']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_user_field_user_parliament']['field'] = 'field_vote_user_field_user_parliament';
  $handler->display->display_options['fields']['field_vote_user_field_user_parliament']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_vote_user_field_user_parliament']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_vote_user_field_user_parliament']['bypass_access'] = 0;
  /* Feld: Politician Reference: Party (indexed) */
  $handler->display->display_options['fields']['field_vote_user_field_user_party']['id'] = 'field_vote_user_field_user_party';
  $handler->display->display_options['fields']['field_vote_user_field_user_party']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_user_field_user_party']['field'] = 'field_vote_user_field_user_party';
  $handler->display->display_options['fields']['field_vote_user_field_user_party']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_vote_user_field_user_party']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_vote_user_field_user_party']['bypass_access'] = 0;
  /* Feld: Politician Reference: Title (indexed) */
  $handler->display->display_options['fields']['field_vote_user_field_user_title']['id'] = 'field_vote_user_field_user_title';
  $handler->display->display_options['fields']['field_vote_user_field_user_title']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_user_field_user_title']['field'] = 'field_vote_user_field_user_title';
  /* Feld: Politician Reference: URL (indexed) */
  $handler->display->display_options['fields']['field_vote_user_url']['id'] = 'field_vote_user_url';
  $handler->display->display_options['fields']['field_vote_user_url']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_user_url']['field'] = 'field_vote_user_url';
  $handler->display->display_options['fields']['field_vote_user_url']['link_to_entity'] = 0;
  /* Feld: Politician Reference » Constituency » Area Codes: Name (indexed) */
  $handler->display->display_options['fields']['field_vote_user_field_user_constituency_field_constituency_area_codes_name']['id'] = 'field_vote_user_field_user_constituency_field_constituency_area_codes_name';
  $handler->display->display_options['fields']['field_vote_user_field_user_constituency_field_constituency_area_codes_name']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_user_field_user_constituency_field_constituency_area_codes_name']['field'] = 'field_vote_user_field_user_constituency_field_constituency_area_codes_name';
  $handler->display->display_options['fields']['field_vote_user_field_user_constituency_field_constituency_area_codes_name']['link_to_entity'] = 0;
  /* Feld: Indexed Inhalt: Vote */
  $handler->display->display_options['fields']['field_vote']['id'] = 'field_vote';
  $handler->display->display_options['fields']['field_vote']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote']['field'] = 'field_vote';
  $handler->display->display_options['fields']['field_vote']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_vote']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_vote']['bypass_access'] = 0;
  /* Feld: Indexed Inhalt: The main body text » Text */
  $handler->display->display_options['fields']['body_value_1']['id'] = 'body_value_1';
  $handler->display->display_options['fields']['body_value_1']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['body_value_1']['field'] = 'body_value';
  $handler->display->display_options['fields']['body_value_1']['link_to_entity'] = 0;
  /* Feld: Parliament: Name (indexed) */
  $handler->display->display_options['fields']['field_parliament_name']['id'] = 'field_parliament_name';
  $handler->display->display_options['fields']['field_parliament_name']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_parliament_name']['field'] = 'field_parliament_name';
  $handler->display->display_options['fields']['field_parliament_name']['link_to_entity'] = 0;
  /* Feld: Politician Reference » Party: Name (indexed) */
  $handler->display->display_options['fields']['field_vote_user_field_user_party_name']['id'] = 'field_vote_user_field_user_party_name';
  $handler->display->display_options['fields']['field_vote_user_field_user_party_name']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_user_field_user_party_name']['field'] = 'field_vote_user_field_user_party_name';
  $handler->display->display_options['fields']['field_vote_user_field_user_party_name']['link_to_entity'] = 0;
  /* Feld: Node Reference: Titel (indexed) */
  $handler->display->display_options['fields']['field_vote_node_title']['id'] = 'field_vote_node_title';
  $handler->display->display_options['fields']['field_vote_node_title']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_node_title']['field'] = 'field_vote_node_title';
  $handler->display->display_options['fields']['field_vote_node_title']['link_to_entity'] = 0;
  /* Feld: Politician Reference » Fraction: Name (indexed) */
  $handler->display->display_options['fields']['field_vote_user_field_user_fraction_name']['id'] = 'field_vote_user_field_user_fraction_name';
  $handler->display->display_options['fields']['field_vote_user_field_user_fraction_name']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['fields']['field_vote_user_field_user_fraction_name']['field'] = 'field_vote_user_field_user_fraction_name';
  $handler->display->display_options['fields']['field_vote_user_field_user_fraction_name']['link_to_entity'] = 0;
  /* Sortierkriterien: Indexed Inhalt: Änderungsdatum */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filterkriterium: Indexed Inhalt: Inhaltstyp */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'vote' => 'vote',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filterkriterium: Suche: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Suche nach Begriff oder PLZ';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    29859578 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'field_vote_user:field_user_constituency:field_constituency_area_codes:name' => 'field_vote_user:field_user_constituency:field_constituency_area_codes:name',
    'field_vote_user:field_user_fname' => 'field_vote_user:field_user_fname',
    'field_vote_user:field_user_lname' => 'field_vote_user:field_user_lname',
  );
  /* Filterkriterium: Politician Reference: Fraction (indexed) */
  $handler->display->display_options['filters']['field_vote_user_field_user_fraction']['id'] = 'field_vote_user_field_user_fraction';
  $handler->display->display_options['filters']['field_vote_user_field_user_fraction']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['field_vote_user_field_user_fraction']['field'] = 'field_vote_user_field_user_fraction';
  $handler->display->display_options['filters']['field_vote_user_field_user_fraction']['value'] = array(
    19744 => '19744',
    19729 => '19729',
    19727 => '19727',
    19726 => '19726',
  );
  $handler->display->display_options['filters']['field_vote_user_field_user_fraction']['group'] = 1;
  $handler->display->display_options['filters']['field_vote_user_field_user_fraction']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_vote_user_field_user_fraction']['expose']['operator_id'] = 'field_vote_user_field_user_fraction_op';
  $handler->display->display_options['filters']['field_vote_user_field_user_fraction']['expose']['label'] = 'Fraktion';
  $handler->display->display_options['filters']['field_vote_user_field_user_fraction']['expose']['operator'] = 'field_vote_user_field_user_fraction_op';
  $handler->display->display_options['filters']['field_vote_user_field_user_fraction']['expose']['identifier'] = 'field_vote_user_field_user_fraction';
  $handler->display->display_options['filters']['field_vote_user_field_user_fraction']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    29859578 => 0,
  );
  $handler->display->display_options['filters']['field_vote_user_field_user_fraction']['expose']['reduce'] = 1;
  /* Filterkriterium: Indexed Inhalt: Vote */
  $handler->display->display_options['filters']['field_vote']['id'] = 'field_vote';
  $handler->display->display_options['filters']['field_vote']['table'] = 'search_api_index_node_index';
  $handler->display->display_options['filters']['field_vote']['field'] = 'field_vote';
  $handler->display->display_options['filters']['field_vote']['value'] = array(
    19669 => '19669',
    19668 => '19668',
    19670 => '19670',
    19667 => '19667',
  );
  $handler->display->display_options['filters']['field_vote']['group'] = 1;
  $handler->display->display_options['filters']['field_vote']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_vote']['expose']['operator_id'] = 'field_vote_op';
  $handler->display->display_options['filters']['field_vote']['expose']['label'] = 'Position';
  $handler->display->display_options['filters']['field_vote']['expose']['operator'] = 'field_vote_op';
  $handler->display->display_options['filters']['field_vote']['expose']['identifier'] = 'field_vote';
  $handler->display->display_options['filters']['field_vote']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    51622513 => 0,
    181527986 => 0,
    140336230 => 0,
    185431326 => 0,
    178386088 => 0,
    29859578 => 0,
  );
  $handler->display->display_options['filters']['field_vote']['expose']['reduce'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-pw-vote-search';
  $translatables['vote_search'] = array(
    t('Master'),
    t('Vote Search'),
    t('mehr'),
    t('Anwenden'),
    t('Zurücksetzen'),
    t('Sortieren nach'),
    t('Aufsteigend'),
    t('Absteigend'),
    t('Wählen Sie eine beliebige Filter und klicken Sie auf Anwenden, um Ergebnisse zu sehen'),
    t('Elemente pro Seite'),
    t('- Alle -'),
    t('Offset'),
    t('« erste Seite'),
    t('‹ vorherige Seite'),
    t('weiter'),
    t('letzte Seite »'),
    t('Mehr laden'),
    t('Beitrags-ID'),
    t('.'),
    t(','),
    t('Parliament'),
    t('Politician'),
    t('The main body text » Text'),
    t('Node Reference'),
    t('Constituency (indexed)'),
    t('First Name (indexed)'),
    t('Gender (indexed)'),
    t('Last name (indexed)'),
    t('Name (indexed)'),
    t('Parliament (indexed)'),
    t('Party (indexed)'),
    t('Title (indexed)'),
    t('URL (indexed)'),
    t('Vote'),
    t('Titel (indexed)'),
    t('Suche nach Begriff oder PLZ'),
    t('Fraktion'),
    t('Position'),
    t('Block'),
  );
  $export['vote_search'] = $view;

  return $export;
}
