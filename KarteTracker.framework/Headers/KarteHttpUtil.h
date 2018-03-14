//
// Created by 中間亮彬 on 2017/12/20.
//

#ifndef KarteHttpUtil_h
#define KarteHttpUtil_h

#import <Foundation/Foundation.h>


@interface KarteHttpUtil : NSObject
+ (NSData *)sendRequest:(NSString *)endpoint postData:(NSData *)postData appKey:(NSString *)appKey;
@end

#endif /* KarteHttpUtil_h */
