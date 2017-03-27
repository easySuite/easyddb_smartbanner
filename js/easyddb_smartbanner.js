/**
 * Initiate SmartBanner object.
 */

(function ($) {
  Drupal.behaviors.easyddb_smartbanner = {
    attach: function(context, settings) {
      var easyddb_smartbanner = settings.easyddb_smartbanner;
      var store = {};
      var price = {};

      var os = ['android', 'ios', 'windows'];
      os.forEach(function (item) {
        if (Drupal.settings.easyddb_smartbanner[item]) {
          store[item] = easyddb_smartbanner[item].description;
          price[item] = easyddb_smartbanner[item].price;
        }
      });

      new SmartBanner({
        daysHidden: Drupal.settings.easyddb_smartbanner.days_hidden,   // days to hide banner after close button is clicked (defaults to 15)
        daysReminder: Drupal.settings.easyddb_smartbanner.days_reminder, // days to hide banner after "VIEW" button is clicked (defaults to 90)
        appStoreLanguage: Drupal.settings.easyddb_smartbanner.app_store_language, // language code for the App Store (defaults to user's browser language)
        title: Drupal.settings.easyddb_smartbanner.app_title,
        author: Drupal.settings.easyddb_smartbanner.app_author,
        button: Drupal.settings.easyddb_smartbanner.button_name,
        store: store,
        price: price,
        icon: easyddb_smartbanner.app_icon.icon_path
      });
    }
  };

})(jQuery);
