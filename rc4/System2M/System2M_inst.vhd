	component System2M is
		port (
			clk_cpu_clk   : in std_logic := 'X'; -- clk
			reset_reset_n : in std_logic := 'X'  -- reset_n
		);
	end component System2M;

	u0 : component System2M
		port map (
			clk_cpu_clk   => CONNECTED_TO_clk_cpu_clk,   -- clk_cpu.clk
			reset_reset_n => CONNECTED_TO_reset_reset_n  --   reset.reset_n
		);

