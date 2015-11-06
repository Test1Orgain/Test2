//
//  AppConfig.m
//  SNBusinessHall
//
//  Created by yangbo on 8/4/14.
//  Copyright (c) 2014 yangbo. All rights reserved.
//

#import "AppConfig.h"
#import "NSString+Extension.h"

static AppConfig *appConfigInstance = nil;

static NSString *const SNEncryptKey = @"sunCloud_2014_sec1"; //加密字符串

//NSUserDefaults存储key
NSString *const SCAccountKey = @"account"; //登录帐号Key
NSString *const SCPwdKey = @"pwd";         //密码Key


@implementation AppConfig

+ (instancetype)shareInstance
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
        appConfigInstance = [[AppConfig alloc] init];
        
    });
    
    return appConfigInstance;
}

- (id)init
{
    if(self = [super init])
    {
        _account = [AppConfig readFormUserDefaultsWithKey:SCAccountKey encrypt:NO];
        _password = [AppConfig readFormUserDefaultsWithKey:SCPwdKey encrypt:YES];
    }
    
    return self;
}


+ (BOOL)saveToUserDefaultsWithValue:(id)value forKey:(NSString *)key encrypt:(BOOL)isEncrypt
{
    if(value == nil || key == nil)
        return NO;
    
    if([value isKindOfClass:[NSString class]] && isEncrypt)
    {
        value = [value snb_encryptWithKey:SNEncryptKey];
    }
    
    [[NSUserDefaults standardUserDefaults] setObject:value forKey:key];
    
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    return YES;
}

+ (id)readFormUserDefaultsWithKey:(NSString *)key encrypt:(BOOL)isEncrypt
{
    if(key == nil)
        return nil;
    
    id value = [[NSUserDefaults standardUserDefaults] objectForKey:key];
    
    if(isEncrypt)
    {
        value = [value snb_decryptWithKey:SNEncryptKey];
    }
    
    return value;
}


// 将UIColor变换为UIImage
+ (UIImage *)createImageWithColor:(UIColor *)color
{
    CGRect rect = CGRectMake(0.0f, 0.0f, 1.0f, 1.0f);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);
    UIImage *theImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return theImage;
}

@end
