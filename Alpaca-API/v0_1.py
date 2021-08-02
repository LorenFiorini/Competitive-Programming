import alpaca_trade_api as t_api


class TradeAPI(object):
	def __init__(self):
		self.end_point = 'https://paper-api.alpaca.markets'
		self.key_id = 'PK96UN311CW27HF4UUAL'
		self.secret_key = 'LWHxhRNZb31Ah6skXTQZqegWrEFI51R2fmIto5IZ'
		self.api = t_api.REST(self.key_id, self.secret_key, self.end_point)
		self.symbol = 'IVV'
		self.current_order = None
		self.last_price = 1
		
		try:
			self.position = int(self.api.get_position(self.symbol).qty)
		except:
			self.position = 0
			print('except')
	
	def submit_order(self, target):
		if self.current_order is not None:
			self.api.cancel_order(self.current_order.key_id)
			
			delta = target - self.position
			if delta == 0:
				return
			print('Processing the order for {} shares.'.format(target))
			
			if delta > 0:
				buy_quantity = delta
				if self.position < 0:
					buy_quantity = min(abs(self.position), buy_quantity)
				print('Buying')
				self.current_order = self.api.submit_order(self.symbol, buy_quantity,'buy','limit','day',self.last_price)
			
			elif delta < 0:
				sell_quantity = abs(delta)
				if self.position > 0:
					sell_quantity = min(abs(self.position), sell_quantity)
				print('Selling {} shares.'.format(sell_quantity))
				self.current_order = self.api.submit_order(self.symbol, sell_quantity, 'sell', 'limit', 'day', self.last_price)
				


if __name__ == "__main__":
    t = TradeAPI()
    t.submit_order(3)
