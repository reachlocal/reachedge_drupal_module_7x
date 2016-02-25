<?php

/**
 * @file
 * Definition of variables for Variable API module.
 */

/**
 * Implements hook_variable_info().
 */
function reachedge_variable_info($options) {

  $variables['reachedge_id'] = array(
    'type' => 'string',
    'title' => t('Site ID', array(), $options),
    'default' => 'XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX',
    'description' => t('This ID is unique to each site you want to track separately, and is in the form of UA-xxxxxxx-yy. To get a Web Property ID, <a href="@analytics">register your site with Google Analytics</a>, or if you already have registered your site, go to your Google Analytics Settings page to see the ID next to every site profile. <a href="@webpropertyid">Find more information in the documentation</a>.',
        array(
          '@analytics' => 'http://www.google.com/analytics/',
          '@webpropertyid' => url('https://developers.google.com/analytics/resources/concepts/gaConceptsAccounts',
        array('fragment' => 'webProperty')),
        ), $options),
    'required' => TRUE,
    'group' => 'reachedge',
    'localize' => TRUE,
    'multidomain' => TRUE,
    'validate callback' => 'reachedge_validate_reachedge_id',
  );

  return $variables;
}

/**
 * Implements hook_variable_group_info().
 */
function reachedge_variable_group_info() {

  $groups['googleanalytics'] = array(
    'title' => t('ReachEdge'),
    'description' => t('Configure tracking behavior to get insights into your website traffic and marketing effectiveness.'),
    'access' => 'administer reachedge tracking',
    'path' => array('admin/config/system/reachedge'),
  );

  return $groups;
}

/**
 * Validate Web Property ID variable.
 */
function reachedge_validate_reachedge_id($variable) {

  if (!preg_match('/^[A-Z0-9]{8}(-[A-Z0-9]{4}){3}-[A-Z0-9]{12}$/i', $variable['value'])) {
    return t('A valid ReachEdge Site ID is formatted like XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX');
  }
}
