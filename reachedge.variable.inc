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
    'description' => t('This Site ID is unique to each site you want to track separately, and is in the form of XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX. <p>Need help finding your ReachEdge Site ID?</p> <ol><li>Sign into <a href="@reachedge_site">ReachEdge</a>.</li><li>Navigate to Settings tab, and click on \'Tracking Code\'.</li><li>Copy the Tracking Code ID out of your tracking code snippet. It should look something like: d4098273-6c87-4672-9f5e-94bcabf5597a <strong>Note:</strong> Do not use the example tracking code id as it will not work properly.</li></ol><p>If you have difficulty with this step or cannot find your Tracking ID, please contact your ReachLocal account representative.</p>',
        array(
          '@reachedge_site' => 'http://edge.reachlocal.com/',
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

  $groups['reachedge'] = array(
    'title' => t('ReachEdge'),
    'description' => t('ReachEdge offers lead &amp; call tracking, lead notifications &amp; nurturing, ROI reports, analytics & insights, and mobile app &amp; alerts.'),
    'access' => 'administer reachedge',
    'path' => array('admin/config/system/reachedge'),
  );

  return $groups;
}

/**
 * Validate ReachEdge Site ID variable.
 */
function reachedge_validate_reachedge_id($variable) {

  if (!preg_match('/^[A-Z0-9]{8}(-[A-Z0-9]{4}){3}-[A-Z0-9]{12}$/i', $variable['value'])) {
    return t('A valid ReachEdge Site ID is formatted like XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX');
  }
}
