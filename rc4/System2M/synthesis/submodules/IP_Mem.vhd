-- new_component.vhd

-- This file was auto-generated as a prototype implementation of a module
-- created in component editor.  It ties off all outputs to ground and
-- ignores all inputs.  It needs to be edited to make it do something
-- useful.
-- 
-- This file will not be automatically regenerated.  You should check it in
-- to your version control system if you want to keep it.

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity IP_Mem is
	port (
		clock      : in  std_logic                     := '0';             --   clk.clk
		reset      : in  std_logic                     := '0';             --   rst.reset_n
		address    : in  std_logic_vector(7 downto 0)  := (others => '0'); -- slave.address
		chipselect : in  std_logic                     := '0';             --      .chipselect
		read       : in  std_logic                     := '0';             --      .read
		readdata   : out std_logic_vector(31 downto 0);                    --      .readdata
		write      : in  std_logic                     := '0';             --      .write
		writedata  : in  std_logic_vector(31 downto 0) := (others => '0')  --      .writedata
	);
end entity;

architecture rtl of IP_Mem is

	signal	AdrsMem, DataMux		: std_logic_vector(7  downto 0);
	signal	DataMem					: std_logic_vector(31 downto 0);

------------------------------------------------------------------------------------
begin
------------------------------------------------------------------------------------

	---------------------------------------------------------
	Process(reset, clock)  begin
	---------------------------------------------------------
	if (reset = '0') then
		readdata <= X"00000000"; DataMem <= X"00000000"; AdrsMem <= X"00"; DataMux <= X"00";
	elsif (clock'event and clock = '1') then
		DataMux <= AdrsMem or DataMem(31 downto 24);
		if (chipselect = '1' and read = '1') then
			readdata <= DataMux & DataMem(23 downto 0);
		end if;
		if (chipselect = '1' and write = '1') then
			AdrsMem <= address;  DataMem <= writedata;
		end if;
	end if;
	end process;

end rtl;
