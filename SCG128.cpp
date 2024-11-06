#include <stdexcept>
#include <cstdint>

class SCG128 {
	public:
		SCG128(__uint128_t seed, __uint128_t multiplier, __uint128_t additive,unsigned int shift) {
			if (multiplier == 0) {
				throw std::invalid_argument("The multiplier can not be 0 (data loss)");
			}
			if (multiplier == 1) {
				throw std::invalid_argument("The multiplier can not be 1 (Why would you even try?)");
			}
			if ((multiplier & 1) == 0) {
				throw std::invalid_argument("The multiplier must be odd (data loss)");
			}
			if (shift == 0) {
				throw std::invalid_argument("The shift value can not be 0 (data loss)");
			}
			if (shift > 127) {
				throw std::invalid_argument("The shift value can not be greater than 127 (otherwise the generator is a LCG)");
			}
			this->state = seed;
			this->mul = multiplier;
			this->add = additive;
			this->shift = shift;
	    }
	    // returns a 32 bit integer
		uint32_t get32() {
			state = (state ^ (state >> shift)) * mul * add;
			return static_cast<uint32_t>(state >> 48);
		}
	
		// returns a 64 bit integer
		uint64_t get64() {
			state = (state ^ (state >> shift)) * mul * add;
			return static_cast<uint64_t>(state >> 32);
		}
	private:
		__uint128_t state;
		__uint128_t mul;
		__uint128_t add;
		unsigned int shift;
}
