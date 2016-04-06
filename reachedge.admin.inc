<?php

/**
 * @file
 * Administrative page callbacks for the ReachEdge module.
 */

/**
 * Implements hook_admin_settings().
 */
function reachedge_admin_settings_form($form_state) {

  $form['account'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
  );

  $form['account']['reachedge_id'] = array(
    '#title' => t('Site ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('reachedge_id', 'XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX'),
    '#size' => 38,
    '#maxlength' => 36,
    '#required' => TRUE,
    '#description' => t('This Site ID is unique to each site you want to track separately, and is in the form of XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX. <p>Need help finding your ReachEdge Site ID?</p> <ol><li>Sign into <a href="@reachedge_site">ReachEdge</a>.</li><li>Navigate to Settings tab, and click on \'Tracking Code\'.</li><li>Copy the Tracking Code ID out of your tracking code snippet. It should look something like: d4098273-6c87-4672-9f5e-94bcabf5597a <strong>Note:</strong> Do not use the example tracking code id as it will not work properly.</li></ol><p>If you have difficulty with this step or cannot find your Tracking ID, please contact your ReachLocal account representative.</p>',
        array(
          '@reachedge_site' => 'http://edge.reachlocal.com/',
        )),
  );

  return system_settings_form($form);
}

/**
 * Implements _form_validate().
 */
function reachedge_admin_settings_form_validate($form, &$form_state) {

  if (!preg_match('/^[A-Z0-9]{8}(-[A-Z0-9]{4}){3}-[A-Z0-9]{12}$/i', $form_state['values']['reachedge_id'])) {
    form_set_error('reachedge_id', t('A valid ReachLocal Site ID is formatted like XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX'));
  }

}
