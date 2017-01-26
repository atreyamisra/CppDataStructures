#include "assignment-5_logMgr.h"
#include <stdio.h>
#include <stdlib.h>

/* Your log manager implementations here */
int add_to_log(log_manager* mgr, long timestamp) {
	int maxsize = mgr->window_duration;
	enqueue(mgr->q, timestamp);
	Node_q *pointer = mgr->q->head;
	int i = timestamp;

	while (pointer->next != NULL) {
		int newdata = pointer->data;
		pointer = pointer->next;
		if ((timestamp - newdata) > maxsize) {
			dequeue(mgr->q);
		}
	}

	return mgr->q->size;
}

log_manager* createLogMgr(int delta) {
	log_manager *timeLog = NULL;
	timeLog = malloc(sizeof(log_manager));
	timeLog->q = initialize_q();
	timeLog->window_duration = delta;
	return timeLog;
}