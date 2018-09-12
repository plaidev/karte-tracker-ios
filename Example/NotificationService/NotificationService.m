#import "NotificationService.h"

@interface NotificationService ()

@end

@implementation NotificationService

- (void)didReceiveNotificationRequest:(UNNotificationRequest *)request withContentHandler:(void (^)(UNNotificationContent * _Nonnull))contentHandler {
    
    if ([self canHandleRemoteNotification:request.content.userInfo]) {
        [super didReceiveNotificationRequest:request withContentHandler:contentHandler];
    } else {
        contentHandler(request.content);
    }
}

@end
