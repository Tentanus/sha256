#ifndef SHA_OPERATIONS_H
#define SHA_OPERATIONS_H

#define ROTL(x, n) ((x << n) | (x >> (WORD_SIZE - n)))
#define ROTR(x, n) ((x >> n) | (x << (WORD_SIZE - n)))

#define E(X) ()

/*

	 * Rotates right (circular right shift) value x by n positions [§3.2.4].
	 * @private
	static ROTR(n, x) {
		return (x >>> n) | (x << (32-n));
	}


	 * Logical functions [§4.1.2].
	 * @private
	static Σ0(x) {
	return Sha256.ROTR(2,  x) ^ Sha256.ROTR(13, x) ^ Sha256.ROTR(22, x); }

	static Σ1(x) { return Sha256.ROTR(6,  x) ^ Sha256.ROTR(11, x) ^ Sha256.ROTR(25, x); }
	static σ0(x) { return Sha256.ROTR(7,  x) ^ Sha256.ROTR(18, x) ^ (x>>>3);  }
	static σ1(x) { return Sha256.ROTR(17, x) ^ Sha256.ROTR(19, x) ^ (x>>>10); }
	static Ch(x, y, z)  { return (x & y) ^ (~x & z); }          // 'choice'
	static Maj(x, y, z) { return (x & y) ^ (x & z) ^ (y & z); } // 'majority'
 */

#endif // !#ifndef SHA_OPERATIONS_H
