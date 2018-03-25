//
//  KarteTrackerAppProfile.h
//  Pods
//

#ifndef KarteTrackerAppProfile_h
#define KarteTrackerAppProfile_h

#import <Foundation/Foundation.h>

@interface KarteTrackerAppProfile : NSObject

@property (nonatomic, copy, readonly) NSString *versionName;
@property (nonatomic, copy, readonly) NSString *versionCode;
@property (nonatomic, copy, readonly) NSString *prevVersionName;

- (id)init;
- (void)load;
- (void)save;

@end

#endif /* KarteTrackerAppProfile_h */
