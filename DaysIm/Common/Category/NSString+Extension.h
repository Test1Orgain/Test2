//
//  NSString+Extension.h
//  SNBusinessHall
//
//  Created by yangbo on 8/4/14.
//  Copyright (c) 2014 yangbo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSString (Extension)

/**
 * json字符串转换成NSDictionary
 * @param
 * @return
 */
- (NSDictionary *)snb_JSONValue;

/**
 * base64编码并DES加密
 * @param
 * @return
 */
- (NSString *)snb_encryptWithKey:(NSString *)key;

/**
 * base64解码并DES解密
 * @param
 * @return
 */
- (NSString *)snb_decryptWithKey:(NSString *)key;

/**
 * RSA加密
 * @param
 * @return 
 */
- (NSString *)snb_RSA_encrypt;

- (CGRect)snb_sizeWithFont:(UIFont *)font boundsSize:(CGSize)size;

+ (NSString *)snb_stringFormDate:(NSDate *)date format:(NSString *)format;

@end
