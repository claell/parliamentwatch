<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 *
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

/*
 * preprocess nodes
 */
function parliamentwatch_preprocess_node(&$variables) {
  if ($variables['type'] == 'pw_petition') {
    $node = $variables['node'];

    // default theme suggestion
    $variables['theme_hook_suggestions'][] = 'node__' . $node->type . '__' . $variables['view_mode'];

    $petition_status = field_get_items('node', $node, 'field_petition_status');
    if (!empty($petition_status) && $petition_status[0]['value'] != "open_for_signings") {
      $variables['theme_hook_suggestions'][] = 'node__' . $node->type . '__' . $variables['view_mode'] . '__' . $petition_status[0]['value'];

      if ($petition_status[0]['value'] == "collecting_donations"){
        // Load donation form
        /* This rather complicated way was chosen because the normal module_invoke/
        render method produces only the pure block content (form in this case) and
        not the required div wrappers. Suggestions are welcome: ruh@abgeordnetenwatch.de
        */
        $block = block_load('webform', 'client-block-10508');
        $rendered_block = _block_render_blocks(array($block));
        $rendered_block['webform_client-block-10508']->subject = "";
      }
      // count votes from politicians
      if ($variables['view_mode'] == 'teaser' && in_array($petition_status[0]['value'], array('asking_parliament', 'passed_parliament'))) {
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'vote')
        ->fieldCondition('field_vote_node', 'target_id', $node->nid)
        ->fieldCondition('field_voted', 'value', 1)
        ->fieldCondition('field_parliament', 'tid', $node->field_parliament[LANGUAGE_NONE][0]['tid'])
        ->propertyCondition('status', NODE_PUBLISHED);
        $variables["count_votes"] = $query->count()->execute();
      }
    }
    else {

      // Load signing form
      /* This rather complicated way was chosen because the normal module_invoke/
      render method produces only the pure block content (form in this case) and
      not the required div wrappers. Suggestions are welcome: ruh@abgeordnetenwatch.de
      */
      $block = block_load('webform', 'client-block-10369');
      $rendered_block = _block_render_blocks(array($block));
      $rendered_block['webform_client-block-10369']->subject = "";
    }

    // Due to our complicated block modification above, we need to re-render the block.
    if (empty($petition_status) || $petition_status[0]['value'] == "collecting_donations" || $petition_status[0]['value'] == "open_for_signings"){
      $variables["main_node_form"] = drupal_render(_block_get_renderable_array($rendered_block));
    }
    switch ($variables['field_petition_partner'][0]['value']) {
      case "change.org":
      $variables['partner_html'] = theme('image', array(
        'path' => drupal_get_path('theme', 'parliamentwatch') . '/images/logo-change.png',
        'width' => 119,
        'height' => 23,
        'alt' => 'Change.org',
        ));
      $variables['signing_url'] = url("https://secured.abgeordnetenwatch.de/tools/newsletter.php", array(
        'external' => TRUE,
        'query' => array(
          'width' => 800,
          'height' => 450,
          'iframe' => TRUE,
          'continue' => $variables['field_petition_external_url'][0]['url'],
          )
        ));
      if (empty($petition_status) || $petition_status[0]['value'] == "open_for_signings") {
          // If the petition is run by an external service, all links from
          // the node need to point to that URL. To avoid having to access
          // the nitty-gritty of all elements in use, we simply override
          // the node url in
        $variables['node_url'] = $variables['signing_url'];
      }
      #elseif ($petition_status != "passed_parliament") {
      #  $variables['signing_url'] = $variables['node_url'];
      #}
      break;
      default:
      $variables['partner_html'] = "";
      $variables['signing_url'] = $variables['node_url'];
      break;
    }

    $variables['themed_image'] = theme('image_style', array(
      'style_name' => 'pw_landscape_l', //Configure style here!
      'path' => $variables['field_teaser_image'][0]['uri'],
      ));

    if (!empty($variables['field_teaser_image'][0]['field_image_copyright']) || !empty($variables['field_teaser_image'][0]['field_image_copyright']['und'][0]['value'])) {
      $variables['has_image_copyright'] = TRUE;
    }
  }
  elseif($variables['view_mode'] == 'teaser') {
    $variables['theme_hook_suggestions'][] = 'node__'.$variables['node']->type.'__teaser';
    $variables['theme_hook_suggestions'][] = 'node__'.$variables['node']->nid.'__teaser';
  }
}

/*
 * custom theme functions
 */
function parliamentwatch_theme(&$existing, $type, $theme, $path) {
  return array(
    'user_login' => array(
      'template' => 'templates/user-login',
      'render element' => 'form',
      ),
    );
}

/*
 * adding jqueryui libraries
 */
function parliamentwatch_preprocess_page(&$variables) {
  drupal_add_library('system', 'ui');
  drupal_add_library('system', 'ui.position');
}

/*
 * Implements hook_process_zone().
 */
function parliamentwatch_alpha_process_zone(&$vars) {
  $theme = alpha_get_theme();
  if ($vars['elements']['#zone'] == 'content') {
    $vars['messages'] = FALSE;
  }
}

/**
 * Implements hook_process_region().
 */
function parliamentwatch_alpha_process_region(&$vars) {
  if ($vars['elements']['#region'] == 'content') {
    $theme = alpha_get_theme();
    $vars['messages'] = $theme->page['messages'];
  }
}

/**
 * Customize the linear output of addressfield tokens.
 */
function parliamentwatch_addressfield_formatter__linear($vars) {
  $loc = $vars['address'];

  // Determine which location components to render
  $out = array();
  if (!empty($loc['name_line']) && $vars['name_line']) {
    $out[] = $loc['name_line'];
  }
  if (!empty($loc['organisation_name']) && $vars['organisation_name']) {
    $out[] = $loc['organisation_name'];
  }
  if (!empty($loc['thoroughfare'])) {
    $out[] = $loc['thoroughfare'];
  }
  if (!empty($loc['premise']) && $vars['premise']) {
    $out[] = $loc['premise'];
  }
  if (!empty($loc['administrative_area'])) {
    $out[] = $loc['administrative_area'];
  }
  if (!empty($loc['locality'])) {
    $locality = $loc['locality'];
  }
  if (!empty($loc['postal_code'])) {
    $out[] = $loc['postal_code'].' '.$locality;
  }
  if ($loc['country'] != addressfield_tokens_default_country() && $country_name = _addressfield_tokens_country($loc['country'])) {
    $out[] = $country_name;
  }

  // Render the location components
  $output = implode(', ', $out);

  return $output;
}

/**
 * Implements hook_css_alter().
 */
function parliamentwatch_css_alter(&$css) {
  // Use parliamentwatch horizontal-tabs.css instead of the default one.
  if (isset($css['sites/all/modules/contrib/field_group/horizontal-tabs/horizontal-tabs.css'])) {
    $css['sites/all/modules/contrib/field_group/horizontal-tabs/horizontal-tabs.css']['data'] = drupal_get_path('theme', 'parliamentwatch').'/css/horizontal-tabs.css';
    $css['sites/all/modules/contrib/scroll_to_top/horizontal-tabs.css']['type'] = 'file';
  }
  // Use parliamentwatch scroll_to_top.css instead of the default one.
  if (isset($css['sites/all/modules/contrib/scroll_to_top/scroll_to_top.css'])) {
    $css['sites/all/modules/contrib/scroll_to_top/scroll_to_top.css']['data'] = drupal_get_path('theme', 'parliamentwatch').'/css/scroll_to_top.css';
    $css['sites/all/modules/contrib/scroll_to_top/scroll_to_top.css']['type'] = 'file';
  }
  // Use parliamentwatch jcarousel-default.css instead of the default one.
  if (isset($css['sites/all/modules/contrib/jcarousel/skins/default/jcarousel-default.css'])) {
    $css['sites/all/modules/contrib/jcarousel/skins/default/jcarousel-default.css']['data'] = drupal_get_path('theme', 'parliamentwatch').'/css/jcarousel-default.css';
    $css['sites/all/modules/contrib/scroll_to_top/scroll_to_top.css']['type'] = 'file';
  }
  // change tb_megamenu layout
  if (isset($css['sites/all/modules/contrib/tb_megamenu/css/base.css'])) {
    $css['sites/all/modules/contrib/tb_megamenu/css/base.css']['data'] = drupal_get_path('theme', 'parliamentwatch').'/css/tb_megamenu/base.css';
    $css['sites/all/modules/contrib/tb_megamenu/css/base.css']['type'] = 'file';
  }
  if (isset($css['sites/all/modules/contrib/tb_megamenu/css/default.css'])) {
    $css['sites/all/modules/contrib/tb_megamenu/css/default.css']['data'] = drupal_get_path('theme', 'parliamentwatch').'/css/tb_megamenu/default.css';
    $css['sites/all/modules/contrib/tb_megamenu/css/default.css']['type'] = 'file';
  }
  if (isset($css['sites/all/modules/contrib/tb_megamenu/css/bootstrap.css'])) {
    $css['sites/all/modules/contrib/tb_megamenu/css/bootstrap.css']['data'] = drupal_get_path('theme', 'parliamentwatch').'/css/tb_megamenu/bootstrap.css';
    $css['sites/all/modules/contrib/tb_megamenu/css/bootstrap.css']['type'] = 'file';
  }
}

/**
 * Implements hook_js_alter().
 */
function parliamentwatch_js_alter(&$javascript) {
  $javascript[drupal_get_path('module', 'scroll_to_top').'/scroll_to_top.js']['data'] = drupal_get_path('theme', 'parliamentwatch').'/js/scroll_to_top.js';
}

/**
 * changing the path to the file icons.
 */

function parliamentwatch_file_icon($variables) {
  $file = $variables['file'];
  $icon_directory = drupal_get_path('theme', 'parliamentwatch').'/images/fileicons';

  $mime = check_plain($file->filemime);
  $icon_url = file_icon_url($file, $icon_directory);
  return '<img alt="" class="file-icon" src="'.$icon_url.'" title="'.$mime.'" />';
}


/**
 * slying element for the views_load_more_pager.
 */

function abgeordnetenwatch_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  if ($new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)))) {
    $parameters['page'] = $new_page;
  }

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
        );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  $attributes['href'] = url($_GET['q'], array('query' => $query));
  return '<a'.drupal_attributes($attributes).'><span>'.check_plain($text).'</span></a>';
}


/**
 * slying element for the quicktabs tabs.
 */

function parliamentwatch_qt_quicktabs_tabset($vars) {
  $variables = array(
    'attributes' => array(
      'class' => 'quicktabs-tabs quicktabs-style-'.$vars['tabset']['#options']['style'],
      ),
    'items' => array(),
    );
  foreach (element_children($vars['tabset']['tablinks']) as $key) {
    $item = array();
    if (is_array($vars['tabset']['tablinks'][$key])) {
      $tab = $vars['tabset']['tablinks'][$key];


      if ($key == $vars['tabset']['#options']['active']) {
        $item['class'] = array('active');
      }
      $tab['#title'] = "<span>".$tab['#title']."</span>";
      $tab['#options']['html'] = TRUE;
      $item['data'] = drupal_render($tab);

      $variables['items'][] = $item;
    }
  }
  return theme('item_list', $variables);
}

/////////////////////////// add sharethis js (ruth)
//////////////////////////////////////////////////////

drupal_add_js('var switchTo5x=false;', 'inline');
drupal_add_js('https://ws.sharethis.com/button/buttons.js', 'external');
drupal_add_js('if (typeof stLight !== \'undefined\') { stLight.options({publisher: "55d7781f-7bd9-4944-acee-84f832478498"});}', 'inline');


/////////////////////////// customize addthis button (ruth)
//////////////////////////////////////////////////////

function parliamentwatch_addthis_element($variables) {
  $element = $variables['addthis_element'];
  $element['#attributes']['src'] = '/sites/all/themes/custom/abgeordnetenwatch/images/ic_share.png';
  if (!isset($element['#value'])) {
    return '<'.$element['#tag'].drupal_attributes($element['#attributes'])." />\n";
  }

  $output = '<'.$element['#tag'].drupal_attributes($element['#attributes']).'>';
  if (isset($element['#value_prefix'])) {
    $output .= $element['#value_prefix'];
  }
  $output .= $element['#value'];
  if (isset($element['#value_suffix'])) {
    $output .= $element['#value_suffix'];
  }
  $output .= '</'.$element['#tag'].">\n";
  return $output;
}


/////////////////////////// customize breadcrumb seperator (ruth)
//////////////////////////////////////////////////////

function parliamentwatch_delta_blocks_breadcrumb($variables) {
  $output = '';

  $menu_item = menu_get_item();

  // only rewrite non basic pages
  if(!isset($menu_item['page_arguments'][0]->type) || $menu_item['page_arguments'][0]->type != 'page'){

    $variables['breadcrumb'] = array(l('Startseite', '/'));

    // add parliament
    $parliament = _pw_get_current_parliament_term();
    if($parliament){
      $parliament_name = strtolower($parliament->name);
      $variables['breadcrumb'][] = l('Parlamente', 'http://www.abgeordnetenwatch.de/parlamente-210-0.html');

      // breadcrumb only if not on parliament page
      if(!isset($menu_item['page_arguments'][0]->tid) || $menu_item['page_arguments'][0]->tid != $parliament->tid){
        $variables['breadcrumb'][] = l($parliament->name, 'taxonomy/term/'.$parliament->tid);
      }
    }

    // taxonomy term views integrator
    if($menu_item['page_callback'] == 'tvi_render_view'){

      // blog tags and categories
      if(in_array($menu_item['page_arguments'][0]->vocabulary_machine_name, array('blogtags', 'blogcategories'))){
        $variables['breadcrumb'][] = l('Blog', 'blog');
      }
    }

    // views
    elseif($menu_item['page_callback'] == 'views_page'){

      // views pages under about us
      if(in_array($menu_item['page_arguments'][0], array('press_articles', 'press_release'))){
        $variables['breadcrumb'][] = l('Über uns', 'ueber-uns');
      }

      // view page calendar
      elseif($menu_item['page_arguments'][0] == 'calendar'){
        $user = user_load_by_name($menu_item['page_arguments'][2]);
        parliamentwatch_breadcrumb_user($variables, $user);
      }

      // view profile fields
      elseif($menu_item['page_arguments'][0] == 'pw_user_profile_fields_rev'){
       $user = user_load_by_name($menu_item['page_arguments'][2]);
       $role = _pw_user_has_role($user, 'Candidate')?'Candidate':'Deputy';
       parliamentwatch_breadcrumb_user($variables, $user, $parliament_name, $role);
     }

      // view profile fields
     elseif($menu_item['page_arguments'][0] == 'pw_user_profile_fields_rev'){
       $user = user_load_by_name($menu_item['page_arguments'][2]);
       $role = _pw_user_has_role($user, 'Candidate')?'Candidate':'Deputy';
       parliamentwatch_breadcrumb_user($variables, $user, $parliament_name, $role);
     }
   }

   // nodes and user profiles
   else{

      // add profiles overview to profile
    if(arg(0) == 'user' || arg(0) == 'profile'){
      $user = _pw_get_current_user();
      $role = _pw_user_has_role($user, 'Candidate')?'Candidate':'Deputy';
      parliamentwatch_breadcrumb_user($variables, $user, $parliament_name, $role, FALSE);
    }

      // add parent path to nodes
    elseif (arg(0) == 'node') {
      switch($menu_item['page_arguments'][0]->type){
        case 'pw_petition':
        $variables['breadcrumb'][] = l('Petitionen', 'petitions/'.$parliament_name);
        break;
        case 'poll':
        $variables['breadcrumb'][] = l('Abstimmungen', 'polls/'.$parliament_name);
        break;
        case 'blogpost':
        $variables['breadcrumb'][] = l('Blog', 'blog');
        break;
        case 'newsletter':
        $variables['breadcrumb'][] = l('Newsletter', 'newsletter');
        break;
        case 'press_release':
        $variables['breadcrumb'][] = l('Über uns', 'ueber-uns');
        $variables['breadcrumb'][] = l('Pressemitteilungen', 'about/press/press-releases');
        break;
        case 'dialogue':
        $recipient_uid = $menu_item['page_arguments'][0]->field_dialogue_recipient[LANGUAGE_NONE][0]['target_id'];
        if(isset($parliament_name) && !empty($recipient_uid)){

            // find revision by uid and parliament
          $query = db_select('user_archive_cache', 'uac');
          $query->fields('uac', array('uid', 'vid', 'user_role', 'actual_profile'));
          $query->condition("parliament_name", $parliament_name);
          $query->condition("uid", $recipient_uid);
          $result = $query->execute();
          if($result->rowCount() > 0){
            $uac_obj = $result->fetchObject();
            $user = user_revision_load($recipient_uid, $uac_obj->vid);
            $role = ucfirst($uac_obj->user_role);
            $is_actual_profile = $uac_obj->actual_profile == 1;

              // add parliament and profile to breadcrumb
            parliamentwatch_breadcrumb_user($variables, $user, $parliament_name, $role, !$is_actual_profile);
          }
        }
        break;
        case 'calendar_entry':
        $author_uid = $menu_item['page_arguments'][0]->uid;
        $user = user_load($author_uid);

          // add only profile to breadcrumb
        parliamentwatch_breadcrumb_user($variables, $user);

          // add calendar overview
        $variables['breadcrumb'][] = l('Wahlkampftermine', 'profile/'.$user->name.'/calendar');
        break;
      }
    }
  }
}

  // load active trail
$active_trail = menu_get_active_trail();
$last_item = end($active_trail);

  // add current item
    //if ($variables['breadcrumb_current'] && current_path() != $last_item['href']) {
$title = drupal_get_title();
if(!empty($title)) {
  $variables['breadcrumb'][] = l($title, current_path(), array('html' => TRUE));
}
else {
  $variables['breadcrumb'][] = l($last_item['link_title'], current_path(), array('html' => TRUE));
}
    //}
  // create output
$output = '<div id="breadcrumb" class="clearfix"><ul class="breadcrumb">';
$switch = array('odd' => 'even', 'even' => 'odd');
$zebra = 'even';
$last = count($variables['breadcrumb']) - 1;

foreach ($variables['breadcrumb'] as $key => $item) {
  $zebra = $switch[$zebra];
  $attributes['class'] = array('depth-'.($key + 1), $zebra);
  if ($key == 0) {
    $attributes['class'][] = 'first';
  }
  if ($key == $last) {
    $attributes['class'][] = 'last';
  }
  if ($key != $last) {
    $output .= '<li'.drupal_attributes($attributes).'>'.$item.' / </li>';
  }
  else{
    $output .= '<li'.drupal_attributes($attributes).'>'.$item.'</li>';
  }
}

$output .= '</ul></div>';
  //}

return $output;
}

/**
 * Implements hook_breadcrumbs_alter().
 */
function parliamentwatch_menu_breadcrumb_alter(&$active_trail, $item){
  foreach ($active_trail as $index => &$value) {

    // Landtage and Parlamente are the same but we need Landtage for structuring the menu
    if($value['title'] == 'Landtage'){
      unset($active_trail[$index]);
      continue;
    }

    // remove icon class menu attibutes for rendering as breadcrumb
    foreach($value['options']['attributes']['class'] as $index_class => $class){
      if(strpos($class, 'icon') > -1){
        unset($value['options']['attributes']['class'][$index_class]);
      }
    }
    foreach($value['localized_options']['attributes']['class'] as $index_class => $class){
      if(strpos($class, 'icon') > -1){
        unset($value['localized_options']['attributes']['class'][$index_class]);
      }
    }
  }
}

function parliamentwatch_breadcrumb_user(&$variables, $user, $parliament_name = FALSE, $role = FALSE, $set_profile = TRUE){
  if($role){
    if($role == 'Candidate') {
      $variables['breadcrumb'][] = l('Kandidierende', 'profile/'.$parliament_name.'/candidates');
    }
    else{
      $variables['breadcrumb'][] = l('Abgeordnete', 'profile/'.$parliament_name.'/deputies');
    }
  }
  if($set_profile){
    $user_title = field_get_items('user', $user, 'field_user_title');
    $user_first_name = field_get_items('user', $user, 'field_user_fname');
    $user_last_name = field_get_items('user', $user, 'field_user_lname');
    $user_full_name = trim($user_title[0]['value'].' '.$user_first_name[0]['value'].' '.$user_last_name[0]['value']);
    if($set_archive_path){
      $variables['breadcrumb'][] = l($user_full_name, 'profile/'.$user->name.'/archive/'.$user->vid);
    }
    else{
      $variables['breadcrumb'][] = l($user_full_name, 'user/'.$user->uid);
    }
  }
}

/////////////////////////// customize forms (ruth)
//////////////////////////////////////////////////////

function parliamentwatch_form_comment_form_alter(&$form, &$form_state) {
  global $user;
  if ($user->uid) {
    $form['author']['_author']['#title'] = t('You are logged in as');
  }
  $form['actions']['submit']['#value'] = t('Add comment');
  $form['author']['homepage']['#access'] = FALSE;
}
function parliamentwatch_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'webform_client_form_104846') {
    $form['#attributes']['class'][] = 'row';
    $form['actions']['#attributes']['class'][] = 'col-sm-4';
    $form['actions']['submit']['#attributes']['class'][] = 'big';
  }
}

/////////////////////////// customize RSS block (ruth)
//////////////////////////////////////////////////////

function parliamentwatch_feed_icon($variables) {
  $text = t('Subscribe to @feed-title', array('@feed-title' => $variables['title']));
  if ($image = theme('image', array('path' => 'misc/feed.png', 'width' => 16, 'height' => 16, 'alt' => $text))) {
    return l($text, $variables['url'], array('html' => TRUE, 'attributes' => array('class' => array('feed-link'), 'title' => $text)));
  }
}

/////////////////////////// hide the more link in tagclouds (ruth)
//////////////////////////////////////////////////////

function parliamentwatch_tagadelic_weighted(array $vars) {
  $terms = $vars['terms'];
  $output = '';

  foreach ($terms as $term) {
    $output .= l($term->name, 'taxonomy/term/'.$term->tid, array(
      'attributes' => array(
        'class' => array("tagadelic", "level".$term->weight),
        'rel' => 'tag',
        'title'  => $term->description,
        )
      )
    )." \n";
  }
  //if (count($terms) >= variable_get('tagadelic_block_tags_'.$vars['voc']->vid, 12)) {
  //  $output .= theme('more_link', array('title' => t('more tags'), 'url' => "tagadelic/chunk/{$vars['voc']->vid}"));
  //}
  return $output;
}


/////////////////////////// cusomize the pager (waqar)
//////////////////////////////////////////////////////

function parliamentwatch_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => ('1'), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ prev')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => ($pager_max), 'element' => $element, 'parameters' => $parameters));

  global $base_path;

  //set first page link
  $first = $li_first;

  //set last page link
  $last = $li_last;


  //add left side arrow and text
  if ($li_previous == ""){
    $new_li_first = '<span>'.t('‹ prev').'</span>';
  }else {
    $new_li_previous = $li_previous;
    $new_li_first = str_replace(t('‹ prev'),''.t('‹ prev'),	$new_li_previous);
  }

  //add rigth side arrow and text
  if ($li_next == ""){
    $new_li_last = '<span>'.t('next ›').'</span>';
  }else {
    $new_li_next = $li_next;
    $new_li_last = str_replace(t('next ›'),	t('next ›'),	$new_li_next);
        //$new_li_last = t('next ›').' '.$new_li_last;
  }

  if ($pager_total[$element] > 1) {
//    if ($li_first) {
    $items[] = array(
      'class' => array('pager-first'),
      'data' => $new_li_first,
      );
//    }
//    if ($li_previous) {
    $items[] = array(
      'class' => '',
      'data' => t('Page'),
      );
//    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => $first.' …',
          );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
            );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current'),
            'data' => $i,
            );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
            );
        }
      }
      if ($i < $pager_max+1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '… '.$last,
          );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => '',
        );
    }
//    if ($li_last) {
    $items[] = array(
      'class' => array('pager-last'),
      'data' => $new_li_last,
      );
//    }
    return '<h2 class="element-invisible">'.t('Pages').'</h2>'.theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
      ));
  }
}


/////////////////////////// hide filter tips
//////////////////////////////////////////////////////

function parliamentwatch_filter_tips_more_info() {
  return '';
}
