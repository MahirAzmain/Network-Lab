//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

package messagepassing;

import ned.IdealChannel;


//
// TODO auto-generated type
//
network SimpleNet
{
    types:
        simple Node
        {
            gates:
                input in;
                output out;
        }

    submodules:
        pc1: Node;
        pc2: Node;
    connections:
        pc1.out --> IdealChannel --> pc2.in;
        pc2.out --> IdealChannel --> pc1.in;
}
