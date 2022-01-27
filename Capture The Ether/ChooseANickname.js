

before(async () => {
  accounts = await ethers.getSigners();
  eoa = accounts[0];
  const factory =  await ethers.getContractFactory("CallMeChallenge")
  contract = factory.attach(`0x7e53cBe1AE1D8BCc1e4273ED31eb61bC4513C509`)
});

it("solves the challenge", async function () {
  const tx = await contract.callme();
  await tx.wait()
  expect(tx.hash).to.not.be.undefined
});



