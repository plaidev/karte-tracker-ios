//
//  KarteBackgroundTask.h
//  KarteTracker
//
//  Created by Tomoki Koga on 2020/06/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class KarteBackgroundTask;

@protocol KarteBackgroundTaskDelegate <NSObject>
@optional
- (BOOL)backgroundTaskShouldStart:(KarteBackgroundTask *)backgroundTask;
- (void)backgroundTaskWillStart:(KarteBackgroundTask *)backgroundTask;
- (void)backgroundTaskDidFinish:(KarteBackgroundTask *)backgroundTask;
@end


@interface KarteBackgroundTask : NSObject
@property (nonatomic, weak) id<KarteBackgroundTaskDelegate> delegate;

- (void)start;
- (void)finish;
- (void)observeLifecycle;
- (void)unobserveLifecycle;
@end

NS_ASSUME_NONNULL_END
