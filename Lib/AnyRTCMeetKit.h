//
//  AnyrtcM2Mutlier.h
//  anyrtc
//
//  Created by EricTao on 15/12/21.
//  Copyright © 2015年 EricTao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AnyRTC.h"

@protocol AnyRTCMeetDelegate <NSObject>

/** Enter metting secuess
 *
 * @param strAnyrtcId	AnyRTC的ID
 */
- (void) OnRtcJoinMeetOK:(NSString*) strAnyrtcId;

/** Enter metting failed
 *
 * @param strAnyrtcId	AnyRTC的ID
 * @param code	 error code
 * @param strReason		The reason for the error
 */
- (void) OnRtcJoinMeetFailed:(NSString*) strAnyrtcId withCode:(AnyRTCErrorCode)code withReason:(NSString*) strReason;

/** Leave meeting
 *
 *  node：abnormal exit or when there will be the callback is put forward
 */
- (void) OnRtcLeaveMeet:(int) code;
/** Video  window size
 *
 * @param videoView	  Video view
 * @param size  the size of video view
 */
- (void) OnRtcVideoView:(UIView*)videoView didChangeVideoSize:(CGSize)size;
/** The remote view into the meeting
 *
 *  @param channelID   channel id
 *  @param remoteView  the remote view
 */
- (void) OnRtcOpenRemoteView:(NSString*)channelID  withRemoteView:(UIView *)removeView;

/** The remote view leave the meeting
 *
 *  @param channelID  channel id
 */
- (void)OnRtcRemoveRemoteView:(NSString*)channelID;

/** State of the remote video audio and video
 *
 *  @param channelID   channel id
 *  @param audioEnable  if the audioEnable is ture/false,the remote audio is close/open
 *  @param videoEnable  if the videoEnable is ture/false,the remote video is close/open
 */
- (void)OnRtcRemoteAVStatus:(NSString*)channelID withAudioEnable:(BOOL)audioEnable withVideoEnable:(BOOL)videoEnable;
@end


@interface AnyRTCMeetVideoItem : NSObject

@property (nonatomic, strong) UIView *videoView;   // local or remote view
@property (nonatomic, strong) NSString *channelID; // the user channel ID of view
@property (nonatomic) BOOL isBack;                 // the direction of local camera (default is NO) ,if the video is remote ,the parameter is failure (Recommended not to set up)
@property (nonatomic) CGSize videoSize;            // record the video size

@end


@interface AnyRTCMeetKit : NSObject {
    
}
/**Initializes the AnyRTCMeetKit object.
 *
 *  @param delegate
 *  @param localViewItem local video view parameter
 *
 *  @return an object of AnyRTCMeetKit class
 */
- (instancetype)initWithDelegate:(id<AnyRTCMeetDelegate>)delegate
               withLocalViewItem:(AnyRTCMeetVideoItem *)localViewItem;

/** Join meeting
 *
 *  @param strAnyrtcId , meeting id
 */
- (BOOL) Join:(NSString*)strAnyrtcId;

/** Leave meeting ,when you call this method,this class will be dealloc
 *
 */
- (void) Leave;

/** SetLocalAudioEnable (default is YES)
 *
 *  @param enable set YES to enable, NO to disable.
 */
- (void) SetLocalAudioEnable:(BOOL)enable;

/** SetLocalVideoEnable (default is YES)
 *
 *  @param enable set YES to enable, NO to disable.
 */
- (void) SetLocalVideoEnable:(BOOL)enable;

/** SetSpeakerEnable (default is YES)
 *
 *  @param enable set YES to enable, NO to disable.
 */
- (void) SetSpeakerEnable:(BOOL)enable;

/** SetproximityMonitoringEnabled  (default is NO)
 *
 *  @param enable set YES to enable, NO to disable.
 */
- (void) SetproximityMonitoringEnabled:(BOOL)enable;

/** SwitchCamera  font/back local camera
 *
 */
- (void) SwitchCamera;

@end