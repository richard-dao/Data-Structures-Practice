Set<String> hashSet = new HashSet<String>();
		hashSet.add("Zero");
		hashSet.add("Three");
		hashSet.add("One");
		hashSet.add("Two");
		hashSet.add("Zero");
		hashSet.add("Negative One");
		hashSet.add("Negative Two");
		hashSet.remove("Negative Two");
		hashSet.remove("Zero");
	
		Iterator<String> itr = hashSet.iterator();
		while (itr.hasNext()) {
			String next = itr.next();
			System.out.print(next + ", ");
			itr.remove();
		}
		
		for (String s : hashSet) {
			System.out.print(s + ", ");
		}
