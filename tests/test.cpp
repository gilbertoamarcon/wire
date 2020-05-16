#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "geom.hpp"


SCENARIO( "Pos can be incremented", "[inc]" ) {

	GIVEN( "a new point" ) {

		Geom::Pos a(2.0,1.0);
		Geom::Pos b(3.0,4.0);

		REQUIRE( a.x == 2.0 );
		REQUIRE( a.y == 1.0 );
		REQUIRE( b.x == 3.0 );
		REQUIRE( b.y == 4.0 );

		WHEN( "increment a with b" ) {
			a += b;
			THEN( "have a = a+b" ) {
				REQUIRE( a.x == 5.0 );
				REQUIRE( a.y == 5.0 );
			}
		}

	}

}
