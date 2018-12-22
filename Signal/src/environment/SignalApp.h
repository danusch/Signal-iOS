//
//  Copyright (c) 2018 Open Whisper Systems. All rights reserved.
//

#import "ConversationViewController.h"

NS_ASSUME_NONNULL_BEGIN

@class AccountManager;
@class CallService;
@class CallUIAdapter;
@class HomeViewController;
@class NotificationsManager;
@class OWSMessageFetcherJob;
@class OWSNavigationController;
@class OWSWebRTCCallMessageHandler;
@class OutboundCallInitiator;
@class TSThread;

@interface SignalApp : NSObject

@property (nonatomic, nullable, weak) HomeViewController *homeViewController;
@property (nonatomic, nullable, weak) OWSNavigationController *signUpFlowNavigationController;

- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)sharedApp;

- (void)setup;

#pragma mark - Conversation Presentation

- (void)presentConversationForRecipientId:(NSString *)recipientId animated:(BOOL)isAnimated;

- (void)presentConversationForRecipientId:(NSString *)recipientId
                                   action:(ConversationViewAction)action
                                 animated:(BOOL)isAnimated;

- (void)presentConversationForThreadId:(NSString *)threadId animated:(BOOL)isAnimated;

- (void)presentConversationForThread:(TSThread *)thread animated:(BOOL)isAnimated;

- (void)presentConversationForThread:(TSThread *)thread action:(ConversationViewAction)action animated:(BOOL)isAnimated;

- (void)presentConversationForThread:(TSThread *)thread
                              action:(ConversationViewAction)action
                      focusMessageId:(nullable NSString *)focusMessageId
                            animated:(BOOL)isAnimated;

#pragma mark - Methods

+ (void)resetAppData;

+ (void)clearAllNotifications;

- (void)showHomeView;

@end

NS_ASSUME_NONNULL_END
