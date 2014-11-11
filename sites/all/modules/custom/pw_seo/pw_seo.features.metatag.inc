<?php
/**
 * @file
 * pw_seo.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function pw_seo_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[current-page:title] | [site:name]',
      ),
      'generator' => array(
        'value' => 'Drupal 7 (http://drupal.org)',
      ),
      'canonical' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
      ),
      'itemprop:name' => array(
        'value' => '[current-page:title]',
      ),
      'og:site_name' => array(
        'value' => '[site:name]',
      ),
      'og:title' => array(
        'value' => '[current-page:title]',
      ),
      'og:type' => array(
        'value' => 'article',
      ),
      'og:url' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'twitter:card' => array(
        'value' => 'summary',
      ),
      'twitter:title' => array(
        'value' => '[current-page:title]',
      ),
      'twitter:url' => array(
        'value' => '[current-page:url:absolute]',
      ),
    ),
  );

  // Exported Metatag config instance: global:403.
  $config['global:403'] = array(
    'instance' => 'global:403',
    'disabled' => FALSE,
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'itemprop:name' => array(
        'value' => '[current-page:title]',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'twitter:title' => array(
        'value' => '[site:name]',
      ),
      'twitter:url' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:404.
  $config['global:404'] = array(
    'instance' => 'global:404',
    'disabled' => FALSE,
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'itemprop:name' => array(
        'value' => '[current-page:title]',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'twitter:title' => array(
        'value' => '[site:name]',
      ),
      'twitter:url' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:frontpage.
  $config['global:frontpage'] = array(
    'instance' => 'global:frontpage',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[site:name] | [site:slogan]',
      ),
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'itemprop:name' => array(
        'value' => '[current-page:title]',
      ),
      'og:description' => array(
        'value' => '[site:slogan]',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'twitter:description' => array(
        'value' => '[site:slogan]',
      ),
      'twitter:title' => array(
        'value' => '[site:name]',
      ),
      'twitter:url' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:summary]',
      ),
      'itemprop:description' => array(
        'value' => '[node:summary]',
      ),
      'itemprop:name' => array(
        'value' => '[current-page:title]',
      ),
      'article:modified_time' => array(
        'value' => '[node:changed:custom:c]',
      ),
      'article:published_time' => array(
        'value' => '[node:created:custom:c]',
      ),
      'og:description' => array(
        'value' => '[node:summary]',
      ),
      'og:title' => array(
        'value' => '[node:title]',
      ),
      'og:updated_time' => array(
        'value' => '[node:changed:custom:c]',
      ),
      'twitter:description' => array(
        'value' => '[node:summary]',
      ),
      'twitter:title' => array(
        'value' => '[node:title]',
      ),
    ),
  );

  // Exported Metatag config instance: node:blogpost.
  $config['node:blogpost'] = array(
    'instance' => 'node:blogpost',
    'config' => array(
      'abstract' => array(
        'value' => '[node:summary]',
      ),
      'robots' => array(
        'value' => array(
          'index' => 'index',
          'follow' => 'follow',
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'itemtype' => array(
        'value' => 'Blog',
      ),
      'itemprop:name' => array(
        'value' => 'abgeordnetenwatch.de: [node:title]',
      ),
      'og:type' => array(
        'value' => 'blog',
      ),
      'og:title' => array(
        'value' => 'abgeordnetenwatch.de: [node:title]',
      ),
      'twitter:title' => array(
        'value' => 'abgeordnetenwatch.de: [node:title]',
      ),
    ),
  );

  // Exported Metatag config instance: node:press_release.
  $config['node:press_release'] = array(
    'instance' => 'node:press_release',
    'config' => array(
      'abstract' => array(
        'value' => '[node:summary]',
      ),
      'robots' => array(
        'value' => array(
          'index' => 'index',
          'follow' => 'follow',
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'itemtype' => array(
        'value' => 'Article',
      ),
      'itemprop:name' => array(
        'value' => 'PM abgeordnetenwatch.de: [node:title]',
      ),
      'og:title' => array(
        'value' => 'PM abgeordnetenwatch.de: [node:title]',
      ),
      'twitter:title' => array(
        'value' => 'PM abgeordnetenwatch.de: [node:title]',
      ),
    ),
  );

  // Exported Metatag config instance: taxonomy_term.
  $config['taxonomy_term'] = array(
    'instance' => 'taxonomy_term',
    'disabled' => FALSE,
    'config' => array(
      'title' => array(
        'value' => '[term:name] | [site:name]',
      ),
      'description' => array(
        'value' => '[term:description]',
      ),
      'itemprop:description' => array(
        'value' => '[term:description]',
      ),
      'itemprop:name' => array(
        'value' => '[term:name]',
      ),
      'og:description' => array(
        'value' => '[term:description]',
      ),
      'og:title' => array(
        'value' => '[term:name]',
      ),
      'twitter:description' => array(
        'value' => '[term:description]',
      ),
      'twitter:title' => array(
        'value' => '[term:name]',
      ),
    ),
  );

  // Exported Metatag config instance: user.
  $config['user'] = array(
    'instance' => 'user',
    'config' => array(
      'title' => array(
        'value' => '[user:field-user-fname] [user:field_user_lname], [user:field-user-party] | [site:name]',
      ),
      'robots' => array(
        'value' => array(
          'index' => 'index',
          'follow' => 'follow',
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'image_src' => array(
        'value' => '[site:url]/sites/abgeordnetenwatch.de/files/styles/pw_portrait_l__normal/public/users/[user:field-user-picture:file]',
      ),
      'itemtype' => array(
        'value' => 'Person',
      ),
      'itemprop:name' => array(
        'value' => '[user:field-user-fname] [user:field_user_lname], [user:field-user-party]',
      ),
      'og:type' => array(
        'value' => 'politician',
      ),
      'og:title' => array(
        'value' => '[user:field-user-fname] [user:field_user_lname], [user:field-user-party]',
      ),
      'og:description' => array(
        'value' => 'Ich habe etwas Interessantes auf abgeordnetenwatch.de gefunden.',
      ),
      'og:image' => array(
        'value' => '[site:url]/sites/abgeordnetenwatch.de/files/styles/pw_portrait_l__normal/public/users/[user:field-user-picture:file]',
      ),
      'profile:username' => array(
        'value' => '[user:name]',
      ),
      'twitter:title' => array(
        'value' => '[user:field-user-fname] [user:field_user_lname], [user:field-user-party]',
      ),
      'twitter:image:src' => array(
        'value' => '[site:url]/sites/abgeordnetenwatch.de/files/styles/pw_portrait_l__normal/public/users/[user:field-user-picture:file]',
      ),
    ),
  );

  return $config;
}
