/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef _MEMORY_CHECKS_HPP_
#define _MEMORY_CHECKS_HPP_

#include <memory>
#include <exception>
#include <iostream>

namespace datasketches {

static inline void ensure_minimum_memory(size_t bytes_available, size_t min_needed) {
  if (bytes_available < min_needed) {
    throw std::out_of_range("Insufficient buffer size detected: bytes available "
    + std::to_string((int) bytes_available) + ", minimum needed " + std::to_string((int) min_needed));
  }  
}

static inline void check_memory_size(size_t requested_index, size_t capacity) {
  if (requested_index > capacity) {
    throw std::out_of_range("Attempt to access memory beyond limits: requested index "
    + std::to_string((int) requested_index) + ", capacity " + std::to_string((int) capacity));
  }
}

// note: size is in bytes, not items
static inline size_t copy_from_mem(const void* src, void* dst, size_t size) {
  memcpy(dst, src, size);
  return size;
}

// note: size is in bytes, not items
static inline size_t copy_to_mem(const void* src, void* dst, size_t size) {
  memcpy(dst, src, size);
  return size;
}

} // namespace

#endif // _MEMORY_CHECKS_HPP_
