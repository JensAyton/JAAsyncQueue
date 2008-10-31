/*

JAAsyncQueue.h

Inter-thread queuing mechanism. Each queue element is an arbitrary object. The
queue supports many-to-many operation; any number of threads can put objects
on the queue, and any number of threads can take objects off the queue or wait
for new objects.


Copyright © 2007 Jens Ayton

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#import <Foundation/Foundation.h>


@interface JAAsyncQueue: NSObject
{
	NSConditionLock				*_lock;
	struct JAAsyncQueueElement	*_head,
								*_tail,
								*_pool;
	unsigned					_elemCount,
								_poolCount;
}

- (BOOL)enqueue:(id)object;	// Returns NO on failure, or if object is nil.

- (id)dequeue;			// Blocks until the queue is non-empty.
- (id)tryDequeue;		// Returns nil if empty.

// Due to the asynchronous nature of the queue, these values are immediately out of date.
- (BOOL)empty;
- (unsigned)count;

- (void)emptyQueue;		// Releases all elements.

@end
