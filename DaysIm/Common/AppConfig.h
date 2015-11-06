//
//  AppConfig.h
//  SNBusinessHall
//
//  Created by yangbo on 8/4/14.
//  Copyright (c) 2014 yangbo. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const SCAccountKey;
extern NSString *const SCPwdKey;

#define PuzzleStyle          @"puzzlestyle"
#define PuzzleStyleScenery   @"scenery"     //风景
#define PuzzleStyleCar       @"car"         //汽车
#define PuzzleStyleBeauty    @"beauty"      //美女
#define PuzzleStyleAnimation @"animation"   //动漫

#define PuzzleCount          @"numberOfPuzzle"   //拼图个数

/**
 * 程序全局状态类
 * @superclass NSObject
 */
@interface AppConfig : NSObject


//用户名登录参数
@property (nonatomic, strong) NSString *account; //当前登陆账户
@property (nonatomic, strong) NSString *password; //当前登陆密码


+ (instancetype)shareInstance;

/**
 * NSUserDefaults存储
 * @param isEncrypt 是否加密(仅支持字符串加密)
 * @return
 */
+ (BOOL)saveToUserDefaultsWithValue:(id)value forKey:(NSString *)key encrypt:(BOOL)isEncrypt;

/**
 * NSUserDefaults读取
 * @param
 * @return
 */
+ (id)readFormUserDefaultsWithKey:(NSString *)key encrypt:(BOOL)isEncrypt;

+ (UIImage *)createImageWithColor:(UIColor *)color;

@end
