/*
  Copyright 2015 Statoil ASA.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
 */

#define BOOST_TEST_MODULE IOCONFIG_INTEGRATION_TEST
#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include <tuple>
#include <vector>
#include <boost/date_time.hpp>

#include <opm/parser/eclipse/Parser/Parser.hpp>
#include <opm/parser/eclipse/EclipseState/EclipseState.hpp>
#include <opm/parser/eclipse/EclipseState/Grid/EclipseGrid.hpp>
#include <opm/parser/eclipse/EclipseState/Schedule/Schedule.hpp>
#include <opm/parser/eclipse/EclipseState/IOConfig/IOConfig.hpp>

using namespace Opm;



BOOST_AUTO_TEST_CASE( NorneResttartConfig ) {
    std::vector<std::tuple<int , bool, boost::gregorian::date> > rptConfig;
    rptConfig.push_back( std::make_tuple(0 , true , boost::gregorian::date( 1997,11,6)) );
    rptConfig.push_back( std::make_tuple(1 , true , boost::gregorian::date( 1997,11,14)) );
    rptConfig.push_back( std::make_tuple(2 , true , boost::gregorian::date( 1997,12,1)) );
    rptConfig.push_back( std::make_tuple(3 , true , boost::gregorian::date( 1997,12,17)) );
    rptConfig.push_back( std::make_tuple(4 , true , boost::gregorian::date( 1998,1,1)) );
    rptConfig.push_back( std::make_tuple(5 , true , boost::gregorian::date( 1998,2,1)) );
    rptConfig.push_back( std::make_tuple(6 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(7 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(8 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(9 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(10 , true , boost::gregorian::date( 1998,4,23)) );
    rptConfig.push_back( std::make_tuple(11 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(12 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(13 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(14 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(15 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(16 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(17 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(18 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(19 , true , boost::gregorian::date( 1998,7,16)) );
    rptConfig.push_back( std::make_tuple(20 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(21 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(22 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(23 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(24 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(25 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(26 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(27 , true , boost::gregorian::date( 1998,10,13)) );
    rptConfig.push_back( std::make_tuple(28 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(29 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(30 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(31 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(32 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(33 , true , boost::gregorian::date( 1999,1,4)) );
    rptConfig.push_back( std::make_tuple(34 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(35 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(36 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(37 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(38 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(39 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(40 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(41 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(42 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(43 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(44 , true , boost::gregorian::date( 1999,5,1)) );
    rptConfig.push_back( std::make_tuple(45 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(46 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(47 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(48 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(49 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(50 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(51 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(52 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(53 , true , boost::gregorian::date( 1999,7,15)) );
    rptConfig.push_back( std::make_tuple(54 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(55 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(56 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(57 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(58 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(59 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(60 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(61 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(62 , true , boost::gregorian::date( 1999,10,3)) );
    rptConfig.push_back( std::make_tuple(63 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(64 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(65 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(66 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(67 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(68 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(69 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(70 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(71 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(72 , true , boost::gregorian::date( 2000,2,1)) );
    rptConfig.push_back( std::make_tuple(73 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(74 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(75 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(76 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(77 , true , boost::gregorian::date( 2000,5,1)) );
    rptConfig.push_back( std::make_tuple(78 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(79 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(80 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(81 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(82 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(83 , true , boost::gregorian::date( 2000,8,1)) );
    rptConfig.push_back( std::make_tuple(84 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(85 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(86 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(87 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(88 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(89 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(90 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(91 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(92 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(93 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(94 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(95 , true , boost::gregorian::date( 2000,11,1)) );
    rptConfig.push_back( std::make_tuple(96 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(97 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(98 , true , boost::gregorian::date( 2001,2,1)) );
    rptConfig.push_back( std::make_tuple(99 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(100 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(101 , true , boost::gregorian::date( 2001,5,1)) );
    rptConfig.push_back( std::make_tuple(102 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(103 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(104 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(105 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(106 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(107 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(108 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(109 , true , boost::gregorian::date( 2001,7,2)) );
    rptConfig.push_back( std::make_tuple(110 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(111 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(112 , true , boost::gregorian::date( 2001,7,16)) );
    rptConfig.push_back( std::make_tuple(113 , true , boost::gregorian::date( 2001,7,30)) );
    rptConfig.push_back( std::make_tuple(114 , true , boost::gregorian::date( 2001,8,1)) );
    rptConfig.push_back( std::make_tuple(115 , true , boost::gregorian::date( 2001,8,10)) );
    rptConfig.push_back( std::make_tuple(116 , true , boost::gregorian::date( 2001,8,16)) );
    rptConfig.push_back( std::make_tuple(117 , true , boost::gregorian::date( 2001,9,1)) );
    rptConfig.push_back( std::make_tuple(118 , true , boost::gregorian::date( 2001,9,10)) );
    rptConfig.push_back( std::make_tuple(119 , true , boost::gregorian::date( 2001,10,1)) );
    rptConfig.push_back( std::make_tuple(120 , true , boost::gregorian::date( 2001,11,1)) );
    rptConfig.push_back( std::make_tuple(121 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(122 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(123 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(124 , true , boost::gregorian::date( 2002,2,1)) );
    rptConfig.push_back( std::make_tuple(125 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(126 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(127 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(128 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(129 , true , boost::gregorian::date( 2002,5,1)) );
    rptConfig.push_back( std::make_tuple(130 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(131 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(132 , true , boost::gregorian::date( 2002,7,8)) );
    rptConfig.push_back( std::make_tuple(133 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(134 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(135 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(136 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(137 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(138 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(139 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(140 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(141 , true , boost::gregorian::date( 2002,10,7)) );
    rptConfig.push_back( std::make_tuple(142 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(143 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(144 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(145 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(146 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(147 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(148 , true , boost::gregorian::date( 2003,1,2)) );
    rptConfig.push_back( std::make_tuple(149 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(150 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(151 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(152 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(153 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(154 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(155 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(156 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(157 , true , boost::gregorian::date( 2003,5,1)) );
    rptConfig.push_back( std::make_tuple(158 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(159 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(160 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(161 , true , boost::gregorian::date( 2003,7,10)) );
    rptConfig.push_back( std::make_tuple(162 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(163 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(164 , true , boost::gregorian::date( 2003,8,12)) );
    rptConfig.push_back( std::make_tuple(165 , true , boost::gregorian::date( 2003,9,1)) );
    rptConfig.push_back( std::make_tuple(166 , true , boost::gregorian::date( 2003,9,2)) );
    rptConfig.push_back( std::make_tuple(167 , true , boost::gregorian::date( 2003,9,10)) );
    rptConfig.push_back( std::make_tuple(168 , true , boost::gregorian::date( 2003,9,12)) );
    rptConfig.push_back( std::make_tuple(169 , true , boost::gregorian::date( 2003,9,13)) );
    rptConfig.push_back( std::make_tuple(170 , true , boost::gregorian::date( 2003,9,16)) );
    rptConfig.push_back( std::make_tuple(171 , true , boost::gregorian::date( 2003,10,1)) );
    rptConfig.push_back( std::make_tuple(172 , true , boost::gregorian::date( 2003,10,23)) );
    rptConfig.push_back( std::make_tuple(173 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(174 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(175 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(176 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(177 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(178 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(179 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(180 , true , boost::gregorian::date( 2004,1,19)) );
    rptConfig.push_back( std::make_tuple(181 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(182 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(183 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(184 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(185 , true , boost::gregorian::date( 2004,5,1)) );
    rptConfig.push_back( std::make_tuple(186 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(187 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(188 , true , boost::gregorian::date( 2004,7,3)) );
    rptConfig.push_back( std::make_tuple(189 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(190 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(191 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(192 , true , boost::gregorian::date( 2004,8,16)) );
    rptConfig.push_back( std::make_tuple(193 , true , boost::gregorian::date( 2004,9,1)) );
    rptConfig.push_back( std::make_tuple(194 , true , boost::gregorian::date( 2004,9,20)) );
    rptConfig.push_back( std::make_tuple(195 , true , boost::gregorian::date( 2004,10,1)) );
    rptConfig.push_back( std::make_tuple(196 , true , boost::gregorian::date( 2004,11,1)) );
    rptConfig.push_back( std::make_tuple(197 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(198 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(199 , true , boost::gregorian::date( 2005,1,12)) );
    rptConfig.push_back( std::make_tuple(200 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(201 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(202 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(203 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(204 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(205 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(206 , true , boost::gregorian::date( 2005,4,24)) );
    rptConfig.push_back( std::make_tuple(207 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(208 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(209 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(210 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(211 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(212 , true , boost::gregorian::date( 2005,7,10)) );
    rptConfig.push_back( std::make_tuple(213 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(214 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(215 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(216 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(217 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(218 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(219 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(220 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(221 , true , boost::gregorian::date( 2005,11,1)) );
    rptConfig.push_back( std::make_tuple(222 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(223 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(224 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(225 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(226 , true , boost::gregorian::date( 2006,1,18)) );
    rptConfig.push_back( std::make_tuple(227 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(228 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(229 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(230 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(231 , true , boost::gregorian::date( 2006,4,25)) );
    rptConfig.push_back( std::make_tuple(232 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(233 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(234 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(235 , true , boost::gregorian::date( 2006,8,1)) );
    rptConfig.push_back( std::make_tuple(236 , false , boost::gregorian::date(1970,1,1)) );
    rptConfig.push_back( std::make_tuple(237 , true , boost::gregorian::date( 2006,8,16)) );
    rptConfig.push_back( std::make_tuple(238 , true , boost::gregorian::date( 2006,9,1)) );
    rptConfig.push_back( std::make_tuple(239 , true , boost::gregorian::date( 2006,9,14)) );
    rptConfig.push_back( std::make_tuple(240 , true , boost::gregorian::date( 2006,10,1)) );
    rptConfig.push_back( std::make_tuple(241 , true , boost::gregorian::date( 2006,10,10)) );


    ParseMode parseMode;
    ParserPtr parser(new Parser());
    DeckConstPtr deck = parser->parseFile("testdata/integration_tests/IOConfig/RPTRST_DECK.DATA", parseMode);
    EclipseState state( deck , parseMode );

    std::shared_ptr<const IOConfig> ioconfig = state.getIOConfigConst();
    for (auto rptrst : rptConfig) {
        int report_step = std::get<0>(rptrst);
        bool save =  std::get<1>(rptrst);
        BOOST_CHECK_EQUAL( save , ioconfig->getWriteRestartFile( report_step ));
        std::cout << "step: " << report_step << " : " << save << std::endl;
    }

}
