//
//  WMZDialogMacro.h
//  WMZDialog
//
//  Created by wmz on 2019/6/5.
//  Copyright © 2019年 wmz. All rights reserved.
//

#ifndef WMZDialogMacro_h
#define WMZDialogMacro_h
//implicit retain of 'self'改为NO
#define WMZDialogStatementAndPropSetFuncStatement(propertyModifier,className, propertyPointerType, propertyName)           \
@property(nonatomic,propertyModifier)propertyPointerType  propertyName;                                                 \
- (className * (^) (propertyPointerType propertyName)) propertyName##Set;

#define WMZDialogSetFuncImplementation(className, propertyPointerType, propertyName)                                       \
- (className * (^) (propertyPointerType propertyName))propertyName##Set{                                                \
return ^(propertyPointerType propertyName) {                                                                            \
_##propertyName = propertyName;                                                                                         \
return self;                                                                                                            \
};                                                                                                                      \
}


#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)


//提供宏定义快捷调用
#define Alert(str) \
Dialog() \
.wMessageSet(str) \
.wStart();  \



#define Device_Dialog_Height [UIScreen mainScreen].bounds.size.height
#define Device_Dialog_Width  [UIScreen mainScreen].bounds.size.width
#define NavigationBar_Dialog_Height (([[UIApplication sharedApplication] statusBarFrame].size.height) + 44)
#define Dialog_GetWNum(A)   (A)/2.0*(Device_Dialog_Width/375)
#define Dialog_GetHNum(B)   (B)/2.0*(Device_Dialog_Height/667)
#define DialogColor(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define DialogK1px (1 / UIScreen.mainScreen.scale)

typedef enum : NSUInteger{
    DialogTypeNornal,               //默认弹窗
    DialogTypeSheet,                //底部弹窗
    DialogTypeAuto,                 //默认弹窗自动消失
    DialogTypeSystemPush,           //系统弹窗
    DialogTypeSystemSheet,          //系统底部弹窗
    DialogTypePay,                  //支付密码框
    DialogTypeShare,                //带分享的弹窗
    DialogTypeWrite,                //带编辑框的弹窗
    DialogTypeSelect,               //带选择的弹窗
    DialogTypePickSelect,           //拾取器弹窗无嵌套
    DialogTypeTime,                 //带倒计时的弹窗
    DialogTypePop,                  //下拉列表选择弹窗
    DialogTypeDown,                 //带下载的弹窗
    DialogTypeMenusSelect,          //下拉无限级菜单弹窗
    DialogTypeAdvertisement,        //广告弹窗
    DialogTypeBuyCar,               //购物车弹窗
    DialogTypeMyView,               //自定义弹窗

}DialogType;

/*
 * type为pop的方向
 */
typedef enum : NSUInteger{
    directionUp,
    directionLeft,
    directionDowm,
    directionright,
    
}DiaDirection;

/*
 * 点击
 */
typedef void (^DialogClickBlock)(id anyID,DialogType type);

/*
 * 多列表点击
 */
typedef void (^DialogMenuClickBlock)(id anyID,NSInteger section,NSInteger row);

/*
 * 带tableview的点击
 */
typedef void (^DialogTableClickBlock)(id anyID,NSIndexPath* path,DialogType type);

/*
 * cell的block
 */
typedef UITableViewCell* (^diaLogCellCallBlock)(NSIndexPath *indexPath,UITableView* tableView,id model);

/*
 * 自定义弹窗
 */
typedef UIView* (^diaLogMyViewCallBlock)(UIView* mainView);

#endif /* WMZDialogMacro_h */