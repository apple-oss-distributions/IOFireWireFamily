/*
 * Copyright (c) 1998-2002 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * Copyright (c) 1999-2003 Apple Computer, Inc.  All Rights Reserved.
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*
	$Log: IOFWQEventSource.cpp,v $
	Revision 1.4  2003/01/31 23:26:22  collin
	*** empty log message ***
	
	Revision 1.3  2002/10/18 23:29:42  collin
	fix includes, fix cast which fails on new compiler
	
	Revision 1.2  2002/09/25 00:27:20  niels
	flip your world upside-down
	
*/

// public
#import <IOKit/firewire/IOFireWireController.h>

// private
#import "IOFWQEventSource.h"

// IOFWQEventSource
OSDefineMetaClassAndStructors(IOFWQEventSource, IOEventSource)

// checkForWork
//
//

bool IOFWQEventSource::checkForWork()
{
    return fQueue->executeQueue(false);
}

// init
//
//

bool IOFWQEventSource::init( IOFireWireController* owner )
{
    fQueue = &owner->getPendingQ();
    return IOEventSource::init(owner);
}