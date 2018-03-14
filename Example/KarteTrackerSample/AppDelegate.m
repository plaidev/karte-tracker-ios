#import "AppDelegate.h"
#import <KarteTracker/KarteTracker.h>
#import <KarteTracker/KarteTrackerConfig.h>
#import <KarteTracker/KarteTrackerUtil.h>
#import <Firebase/Firebase.h>


@interface AppDelegate ()

@end

@implementation AppDelegate

// api_key of KARTE
static NSString *const kAppKey = @"xWveWk7vG3ERsNXFRk9QcMEtdRXpIs70";

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
  
  [FIRApp configure];
  if (floor(NSFoundationVersionNumber) <= NSFoundationVersionNumber_iOS_9_x_Max) {
    UIUserNotificationType allNotificationTypes =
    (UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge);
    UIUserNotificationSettings *settings =
    [UIUserNotificationSettings settingsForTypes:allNotificationTypes categories:nil];
    [application registerUserNotificationSettings:settings];
  } else {
    // iOS 10 or later
#if defined(__IPHONE_10_0) && __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_10_0
    // For iOS 10 display notification (sent via APNS)
    [UNUserNotificationCenter currentNotificationCenter].delegate = self;
    UNAuthorizationOptions authOptions =
    UNAuthorizationOptionAlert
    | UNAuthorizationOptionSound
    | UNAuthorizationOptionBadge;
    [[UNUserNotificationCenter currentNotificationCenter] requestAuthorizationWithOptions:authOptions completionHandler:^(BOOL granted, NSError * _Nullable error) {
    }];
#endif
  }
  
  [application registerForRemoteNotifications];
  KarteTrackerShowLog(YES);
  [KarteTracker setupWithAppKey:kAppKey
                         config:@{}];
  return YES;
}

// called when FCM token is refreshed
- (void)tokenRefreshNotification:(NSNotification *)notification {
  NSString *refreshedToken = [[FIRInstanceID instanceID] token];
  if ( refreshedToken == nil ) {
    NSLog(@"instance id token is nil");
    return;
  }
  NSLog(@"instance id token: %@", refreshedToken);
  
  // send FCM token to KARTE
  [[KarteTracker sharedTracker] registerFCMToken:refreshedToken];
  
  [self connectToFCM];
}

- (void)connectToFCM {
  [[FIRMessaging messaging] connectWithCompletion:^(NSError * _Nullable error){
    if (error != nil){
      NSLog(@"Unable to connect to FCM. %@", error);
    } else {
      NSLog(@"Connected to FCM.");
    }
  }];
}

- (void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings {
  [application registerForRemoteNotifications];
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(nonnull NSData *)deviceToken
{
  NSString *token = deviceToken.description;
  [[FIRInstanceID instanceID] setAPNSToken:deviceToken type:FIRInstanceIDAPNSTokenTypeUnknown];
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(nonnull NSError *)error
{
  NSLog(@"device token error: %@", [error description]);
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo
{
  NSLog(@"push info: %@", [userInfo description]);
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(nonnull NSDictionary *)userInfo fetchCompletionHandler:(nonnull void (^)(UIBackgroundFetchResult))completionHandler
{
  NSLog(@"receive %@",[userInfo description]);
  if( application.applicationState != UIApplicationStateActive ){
    // track notification tapped
    // Capabilities > Background Modes > Remote notifications がoffになっている必要あり
    // onになっている場合、以下のクリックトラッキングが配送直後に実行されてしまう場合がある
    [[KarteTracker sharedTracker] trackNotification:userInfo];
  }else{
    NSLog(@"receive %@",[userInfo description]);
  }
  
  completionHandler(UIBackgroundFetchResultNoData);
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)())completionHandler {
  NSLog(@"userNotificationCenter received notification");
  completionHandler(UNNotificationPresentationOptionAlert);  
}


- (void)applicationWillResignActive:(UIApplication *)application
{
  // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
  // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
  // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
  // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
  [[FIRMessaging messaging] disconnect];
  NSLog(@"disconnected from FCM");
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
  // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
  // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
  [self connectToFCM];
}


@end
