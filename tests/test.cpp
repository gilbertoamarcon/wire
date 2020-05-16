#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "geom.hpp"


SCENARIO( "Pos", "[pos]" ) {

	GIVEN( "two pos, a and b" ) {

		Geom::Pos a(6.0,1.0);
		Geom::Pos b(3.0,4.0);

		REQUIRE( a.x == 6.0 );
		REQUIRE( a.y == 1.0 );
		REQUIRE( b.x == 3.0 );
		REQUIRE( b.y == 4.0 );

		WHEN( "increment a with b" ) {
			a += b;
			THEN( "have a = a+b" ) {
				REQUIRE( a.x == 9.0 );
				REQUIRE( a.y == 5.0 );
			}
		}
		WHEN( "decrement a with b" ) {
			a -= b;
			THEN( "have a = a-b" ) {
				REQUIRE( a.x ==  3.0 );
				REQUIRE( a.y == -3.0 );
			}
		}
		WHEN( "multiply inc a with b" ) {
			a *= b;
			THEN( "have a = a*b" ) {
				REQUIRE( a.x == 18.0 );
				REQUIRE( a.y ==  4.0 );
			}
		}
		WHEN( "divide inc a with b" ) {
			a /= b;
			THEN( "have a = a/b" ) {
				REQUIRE( a.x == 2.00 );
				REQUIRE( a.y == 0.25 );
			}
		}


		WHEN( "a + b" ) {
			Geom::Pos c = a + b;
			THEN( "have c = a+b" ) {
				REQUIRE( c.x == a.x+b.x );
				REQUIRE( c.y == a.y+b.y );
			}
		}
		WHEN( "a - b" ) {
			Geom::Pos c = a - b;
			THEN( "have c = a-b" ) {
				REQUIRE( c.x == a.x-b.x );
				REQUIRE( c.y == a.y-b.y );
			}
		}
		WHEN( "a * b" ) {
			Geom::Pos c = a * b;
			THEN( "have c = a*b" ) {
				REQUIRE( c.x == a.x*b.x );
				REQUIRE( c.y == a.y*b.y );
			}
		}
		WHEN( "a / b" ) {
			Geom::Pos c = a / b;
			THEN( "have c = a/b" ) {
				REQUIRE( c.x == a.x/b.x );
				REQUIRE( c.y == a.y/b.y );
			}
		}



	}

}
