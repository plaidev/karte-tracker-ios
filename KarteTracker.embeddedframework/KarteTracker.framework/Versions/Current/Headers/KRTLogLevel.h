//
//  KRTLogLevel.h
//  KarteTracker
//
//  Created by Tomoki Koga on 2020/02/19.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, KRTLogLevel) {
    KRTLogLevelError = 0,
    KRTLogLevelWarn = 1 << 0,
    KRTLogLevelInfo = 1 << 1,
    KRTLogLevelDebug = 1 << 2,
    KRTLogLevelVerbose = 1 << 3
} NS_SWIFT_NAME(LogLevel);
