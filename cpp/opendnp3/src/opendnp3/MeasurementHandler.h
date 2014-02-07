/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#ifndef __MEASUREMENT_HANDLER_H_
#define __MEASUREMENT_HANDLER_H_

#include <opendnp3/IMeasurementHandler.h>
#include <opendnp3/MeasurementUpdate.h>

#include <openpal/Loggable.h>

#include "HeaderHandlerBase.h"

namespace opendnp3
{

/**
 * Dedicated class for processing response data in the master.
 */
class MeasurementHandler : public HeaderHandlerBase, private openpal::Loggable

{
public:
/**
	* Creates a new ResponseLoader instance.
	*
	* @param arLogger	the Logger that the loader should use for message reporting
	*/
	MeasurementHandler(openpal::Logger& arLogger);	

	void _OnRange(GroupVariation gv, const IterableBuffer<IndexedValue<Binary>>& meas) final;
	void _OnIndexPrefix(GroupVariation gv, const IterableBuffer<IndexedValue<Binary>>& meas) final;

	void _OnRange(GroupVariation gv, const IterableBuffer<IndexedValue<ControlStatus>>& meas) final;
		
	void _OnRange(GroupVariation gv, const IterableBuffer<IndexedValue<Counter>>& meas) final;
	void _OnIndexPrefix(GroupVariation gv, const IterableBuffer<IndexedValue<Counter>>& meas) final;

	void _OnRange(GroupVariation gv, const IterableBuffer<IndexedValue<Analog>>& meas) final;
	void _OnIndexPrefix(GroupVariation gv, const IterableBuffer<IndexedValue<Analog>>& meas) final;

	void _OnRange(GroupVariation gv, const IterableBuffer<IndexedValue<SetpointStatus>>& meas)  final;

	void _OnRangeOfOctets(GroupVariation gv, const IterableBuffer<IndexedValue<openpal::ReadOnlyBuffer>>& meas) final;
	void _OnIndexPrefixOfOctets(GroupVariation gv, const IterableBuffer<IndexedValue<openpal::ReadOnlyBuffer>>& meas) final;
		
	MeasurementUpdate updates;	
};

}



#endif
