
///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2021 Cadence Design Systems, Inc. All rights reserved worldwide.
//
// The code contained herein is the proprietary and confidential information 
// of Cadence or its licensors, and is supplied subject to a previously 
// executed license and maintenance agreement between Cadence and customer. 
// Permission is only granted for use with Cadence high-level synthesis tools and
// may not be used with other high-level synthesis tools. Permission is only 
// granted to distribute the code as indicated. Cadence grants permission for 
// customer to distribute a copy of this code to any partner to aid in designing 
// or verifying the customer's intellectual property, as long as such 
// distribution includes a restriction of no additional distributions from the 
// partner, unless the partner receives permission directly from Cadence.
//
// ALL CODE FURNISHED BY CADENCE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, AND CADENCE SPECIFICALLY DISCLAIMS ANY WARRANTY OF NONINFRINGEMENT, 
// FITNESS FOR A PARTICULAR PURPOSE OR MERCHANTABILITY. CADENCE SHALL NOT BE 
// LIABLE FOR ANY COSTS OF PROCUREMENT OF SUBSTITUTES, LOSS OF PROFITS, 
// INTERRUPTION OF BUSINESS, OR FOR ANY OTHER SPECIAL, CONSEQUENTIAL OR 
// INCIDENTAL DAMAGES, HOWEVER CAUSED, WHETHER FOR BREACH OF WARRANTY, 
// CONTRACT, TORT, NEGLIGENCE, STRICT LIABILITY OR OTHERWISE.
//
////////////////////////////////////////////////////////////////////////////////


// Generated by bdw_memgen 22.01-s003
// Thu Mar 28 10:55:44 CET 2024

#if ! defined hl5_block_1w1r_CC
#define hl5_block_1w1r_CC 1
#if defined STRATUS  &&  ! defined CYN_DONT_SUPPRESS_MSGS
#pragma cyn_suppress_msgs NOTE
#endif	// STRATUS  &&  CYN_DONT_SUPPRESS_MSGS
#include "hl5_block_1w1r.h"
 
#ifdef STRATUS_HLS
   sc_uint<32> hl5_block_1w1r::write0(sc_uint<10> A0, sc_uint<32> D0, bool WE0, bool CE0, sc_uint<1> WEM0) {

      CYN_BIND(WE0,this->WE0);
      CYN_BIND(A0,this->A0);
      CYN_BIND(D0,this->D0);
      CYN_BIND(CE0,this->CE0);
      CYN_BIND(WEM0,this->WEM0);
      HLS_CONFIG_INSTRUCTION( "access_port", 1 );
      mem[A0] = CYN_MASKED_READ( mem[A0], D0, WEM0 );
      return D0;
   }

#endif	// STRATUS_HLS
#ifdef STRATUS_HLS
   void hl5_block_1w1r::nop0(bool WE0, bool CE0, sc_uint<1> WEM0) {
      CYN_BIND(WE0,this->WE0);
      CYN_BIND(CE0,this->CE0);
      CYN_BIND(WEM0,this->WEM0);
      HLS_CONFIG_INSTRUCTION( "access_port", 1 );
   }

#endif	// STRATUS_HLS
#ifdef STRATUS_HLS
   sc_uint<32> hl5_block_1w1r::read1(sc_uint<10> A1, bool CE1) {
      sc_uint<32> Q1;
      CYN_BIND(A1,this->A1);
      CYN_BIND(Q1,this->Q1);
      CYN_BIND(CE1,this->CE1);
      HLS_CONFIG_INSTRUCTION( "access_port", 2 );
      Q1 = mem[A1];
      return Q1;
   }

#endif	// STRATUS_HLS
#ifdef STRATUS_HLS
   void hl5_block_1w1r::nop1(bool CE1) {
      CYN_BIND(CE1,this->CE1);
      HLS_CONFIG_INSTRUCTION( "access_port", 2 );
   }

#endif	// STRATUS_HLS
   void hl5_block_1w1r::thread0() {
#if defined(__GNUC__) && BDW_USE_SCV
    if ( m_p1_tx_0.is_active() ) {
        m_p1_tx_stream->end_write_tx( m_p1_tx_0 );
    }
#endif
    if (CE0 == 1) {
#if defined(__GNUC__)
      // Perform an address range check to prevent crashes on out of bounds
      // accesses in SystemC behavioral simulations.
      if((int)(A0.read()) <= 1023) {
#endif
        if(WE0.read() == 1) {

#if defined(__GNUC__) && defined(BDW_DEBUG_MEMS)
          if (   (sc_time_stamp().to_double() == m_last_read_time) 
		      && (sc_time_stamp().to_double() > 0.0) 
			  && (m_last_read_addr == A0.read().to_uint64())) {
            fprintf(stderr,"WARNING: %s: %s: Both a read and a write were performed at address %d\n", name(), sc_time_stamp().to_string().c_str(), (int)A0.read());
          }
          m_last_write_time = sc_time_stamp().to_double();
          m_last_write_addr = A0.read().to_uint64();
          m_num_errors++;
#if defined(__GNUC__) && (BDW_DEBUG_MEMS > 1)
          if (m_num_errors > BDW_DEBUG_MEMS) {
            fprintf(stderr,"Stopping simulation because more than %d errors have occurred\n", BDW_DEBUG_MEMS );
		    sc_stop();
          }
#endif
#endif
           if ( WEM0.read()[0] == 1 ) {

#if defined(__GNUC__) && BDW_USE_SCV
            m_p1_tx_0 = m_p1_tx_stream->begin_write_tx( A0.read(), D0.read() );
#endif

#if defined(__GNUC__) && defined(BDW_TRACE_MEMS)
        fprintf(stderr,"TRACE: %s%s: %s: write 0x%s to 0x%x\n", name(), ".0", sc_time_stamp().to_string().c_str(), D0.read().range(31,0).to_string(SC_HEX).c_str(), (int)A0.read().to_uint());
#endif
        mem[A0.read().to_uint()].range(31,0) = D0.read().range(31,0);
#if defined(__GNUC__)
            sync_put(A0.read().to_uint());
#endif
           }
        }

#if defined(__GNUC__)
      }
#endif
    }
  }
   void hl5_block_1w1r::thread1() {
#if defined(__GNUC__) && BDW_USE_SCV
    if ( m_p2_tx_0.is_active() ) {
        m_p2_tx_stream->end_tx( m_p2_tx_0, Q1.read() );
    }
#endif
    if (CE1 == 1) {
#if defined(__GNUC__)
      // Perform an address range check to prevent crashes on out of bounds
      // accesses in SystemC behavioral simulations.
      if((int)(A1.read()) <= 1023) {
#endif

#if defined(__GNUC__) && defined(BDW_DEBUG_MEMS)
          if (   (sc_time_stamp().to_double() == m_last_write_time) 
		      && (sc_time_stamp().to_double() > 0.0) 
			  && (m_last_write_addr == A1.read().to_uint64())) {
            fprintf(stderr,"WARNING: %s: %s: Both a read and a write were performed at address %d\n", name(), sc_time_stamp().to_string().c_str(), (int)A1.read());
          }
          m_last_read_time = sc_time_stamp().to_double();
          m_last_read_addr = A1.read().to_uint64();
          m_num_errors++;
#if defined(__GNUC__) && (BDW_DEBUG_MEMS > 1)
          if (m_num_errors > BDW_DEBUG_MEMS) {
            fprintf(stderr,"Stopping simulation because more than %d errors have occurred\n", BDW_DEBUG_MEMS );
		    sc_stop();
          }
#endif
#endif

#if defined(__GNUC__) 
#if BDW_USE_SCV
            m_p2_tx_0 = m_p2_tx_stream->begin_read_tx( A1.read() );
#endif
            sync_get(A1.read().to_uint());
#endif

#if defined(__GNUC__) && defined(BDW_TRACE_MEMS)
        fprintf(stderr,"TRACE: %s: %s: read 0x%s from 0x%x\n", name(), sc_time_stamp().to_string().c_str(), mem[A1.read().to_uint()].to_string(SC_HEX).c_str(), (int)A1.read().to_uint());
#endif
        Q1 = mem[A1.read().to_uint()];
#if defined(__GNUC__)
      }
#endif
    }
  }
#if defined(STRATUS_VLG)
   hl5_block_1w1r::hl5_block_1w1r(const sc_module_name name)
      : sc_module( name ) ,CLK("CLK"),WE0("WE0"),CE0("CE0"),D0("D0"),A0("A0"),WEM0("WEM0"),CE1("CE1"),Q1("Q1"),A1("A1"), mem()
#else
   hl5_block_1w1r::hl5_block_1w1r( sc_module_name name)
      : sc_module( name ) ,CLK("CLK"),WE0("WE0"),CE0("CE0"),D0("D0"),A0("A0"),WEM0("WEM0"),CE1("CE1"),Q1("Q1"),A1("A1"), mem() 
#if defined(__GNUC__) 
#if defined(BDW_DEBUG_MEMS)
		, m_last_read_time(-1), m_last_write_time(-1), m_last_read_addr(0), m_last_write_addr(0), m_num_errors(0)
#endif
		, m_iface(0)
#endif
#endif
   {
#ifdef STRATUS_HLS
      SC_CTHREAD( thread0, (CLK).pos() );
#else
      SC_METHOD( thread0 );
      sensitive << (CLK).pos();

#endif
#ifdef STRATUS_HLS
      SC_CTHREAD( thread1, (CLK).pos() );
#else
      SC_METHOD( thread1 );
      sensitive << (CLK).pos();

#endif
#ifndef STRATUS_HLS
      dont_initialize();
#endif
#if defined(__GNUC__) && BDW_USE_SCV
    esc_enable_scv_logging();
    m_p1_tx_stream = new cynw_scv_memory_tx_stream< sc_uint<10>, sc_uint<32> >( (std::string("sc_main.") + std::string(this->name()) + std::string("_port0")).c_str(), esc_get_scv_tr_db() );
    m_p2_tx_stream = new cynw_scv_memory_tx_stream< sc_uint<10>, sc_uint<32> >( (std::string("sc_main.") + std::string(this->name()) + std::string("_port1")).c_str(), esc_get_scv_tr_db() );
#endif
 
   }

const unsigned long hl5_block_1w1r::implemented = 1;
const unsigned long hl5_block_1w1r::pipelined = 1;
const float hl5_block_1w1r::area = 0;
const float hl5_block_1w1r::delay = 0;
const float hl5_block_1w1r::setup_time = 0;
const unsigned long hl5_block_1w1r::latency_WE0 = 1;
const unsigned long hl5_block_1w1r::latency_WEM0 = 1;
const unsigned long hl5_block_1w1r::latency_CE0 = 1;
const unsigned long hl5_block_1w1r::latency_D0 = 1;
const unsigned long hl5_block_1w1r::latency_A0 = 1;
const unsigned long hl5_block_1w1r::bits_per_maskbit_WEM0 = 32;
const unsigned long hl5_block_1w1r::latency_CE1 = 1;
const unsigned long hl5_block_1w1r::latency_A1 = 1;
const unsigned long hl5_block_1w1r::bits_per_maskbit_WM1 = 0;
const unsigned long hl5_block_1w1r::reg_mem_inputs = 1;
const unsigned long hl5_block_1w1r::reg_mem_outputs = 1;
const unsigned long hl5_block_1w1r::regs_at_mem_inputs = 0;
const unsigned long hl5_block_1w1r::regs_at_mem_outputs = 0;
const unsigned long hl5_block_1w1r::no_spec_reads = 1;
const unsigned long hl5_block_1w1r::is_mem = 1;
const unsigned long hl5_block_1w1r::clock_multiplier = 0;
const bool hl5_block_1w1r::has_extra_ports = false;
const bool hl5_block_1w1r::is_prototype = false;
const char* hl5_block_1w1r::naming_convention = 0;
 
#endif // hl5_block_1w1r_CC

