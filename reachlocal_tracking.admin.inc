<?php

/**
 * @file
 * Administrative page callbacks for the reachlocal tracking module.
 */

/**
 * Implementation of hook_admin_settings() for module settings configuration.
 */
function reachlocal_tracking_admin_settings_form($form_state) {
  $form['account'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
  );

  $form['account']['reachlocal_tracking_id'] = array(
    '#title' => t('Site ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('reachlocal_tracking_id', 'XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX'),
    '#size' => 36,
    '#maxlength' => 36,
    '#required' => TRUE,
    '#description' => t('This ID is unique to each account you would like to track and is in the form of XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX. To get a Site ID, <a href="@reachlocal">sign up with ReachLocal</a>, or if you already have registered your site, go to your ReachLocal Settings.', array('@reachlocal' => 'http://www.reachlocal.com')),
  );

  return system_settings_form($form);
}

/**
 * Implements _form_validate().
 */
function reachlocal_tracking_admin_settings_form_validate($form, &$form_state) {
  
  if (!preg_match('/^[A-Z0-9]{8}(-[A-Z0-9]{4}){3}-[A-Z0-9]{12}$/i', $form_state['values']['reachlocal_tracking_id'])) {
    form_set_error('reachlocal_tracking_id', t('A valid ReachLocal Site ID is formatted like XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX'));
  }

}