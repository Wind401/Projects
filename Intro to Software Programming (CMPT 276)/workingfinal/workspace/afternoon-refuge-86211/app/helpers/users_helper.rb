module UsersHelper
  def gravatar_for(user)
    gravatar_id = Digest::MD5::hexdigest(user.email.downcase)
    default_url = "https%3A%2F%2Fwww.gravatar.com%2Favatar%2Faf0aa7a8aa4f4cd528a0d663379c99ac?s=48"
    gravatar_url = "https://secure.gravatar.com/avatar/#{gravatar_id}?s=48&d=#{default_url}"
    image_tag(gravatar_url, alt: user.email, class: "gravatar") # may change to username once it's added
  end
  
end
